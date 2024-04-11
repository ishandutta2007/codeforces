#include <bits/stdc++.h>
char v[200001];
int main(){
    FILE*fi,*fout;
    int i,n,flag,con;
   // fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    fgetc(fi);
    for(i=1;i<=n;i++)
       v[i]=fgetc(fi);
    flag=0;
    con=0;
    while(flag==0){
       int con1,con2;
       con1=con2=0;
       for(i=1;i<=n;i++)
         if(v[i]=='D'){
            con++;
            con1++;
           // con3++;
            if(con<=0)
                v[i]=-1;
         }
         else if(v[i]=='R'){
             con--;
             con2++;
            // con3++;
             if(con>=0)
                 v[i]=-1;
         }
         if(con1==0)
            flag=1;
         if(con2==0)
            flag=-1;
    }
    if(flag==-1)
          fprintf(fout,"D");
    else
          fprintf(fout,"R");
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}