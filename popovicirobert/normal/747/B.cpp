#include <bits/stdc++.h>
int vf[4];
char s[1000];
int main(){
    FILE*fi,*fout;
    int i,n,j,x;
    char a;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    fgetc(fi);
    if(n%4>0)
       fprintf(fout,"===");
    else{
       x=n/4;
       for(i=1;i<=n;i++) {
         a=fgetc(fi);
         if(a=='A')
             vf[0]++;
         if(a=='C')
             vf[1]++;
         if(a=='G')
             vf[2]++;
         if(a=='T')
             vf[3]++;
         s[i]=a;
       }
       if(vf[0]>x||vf[1]>x||vf[2]>x||vf[3]>x)
          fprintf(fout,"===");
       else{
          for(i=1;i<=n;i++){
            if(s[i]!='?')
                fprintf(fout,"%c" ,s[i]);
            else{
                j=0;
                while(j<4&&vf[j]==x)
                     j++;
                vf[j]++;
                if(j==0)
                    fprintf(fout,"A");
                if(j==1)
                    fprintf(fout,"C");
                if(j==2)
                    fprintf(fout,"G");
                if(j==3)
                    fprintf(fout,"T");
            }
          }
       }
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}