#include <bits/stdc++.h>
int x[4],y[4];
int x2[100],y2[100];
int main(){
    FILE*fi,*fout;
    int i,sx,sy,con,p,X,Y;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    sx=sy=0;
    for(i=1;i<=3;i++){
      fscanf(fi,"%d%d" ,&x[i],&y[i]);
      sx+=x[i];
      sy+=y[i];
    }
    con=0;
    for(i=1;i<=3;i++){
        p=1;
        X=sx-2*x[i];
        Y=sy-2*y[i];
        while(p<=con&&!(x2[p]==X&&y2[p]==Y))
          p++;
        if(p==con+1){
            con++;
            x2[con]=X;
            y2[con]=Y;
        }
    }
    fprintf(fout,"%d\n" ,con);
    for(i=1;i<=con;i++)
         fprintf(fout,"%d %d\n" ,x2[i],y2[i]);
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}