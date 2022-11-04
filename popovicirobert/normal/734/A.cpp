#include <cstdio>

int main(){
    FILE*fi,*fout;
    int n,con1,con2,i;
    char a;
   // fi=fopen("A.in" ,"r");
   //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    fgetc(fi);
    con1=con2=0;
    for(i=1;i<=n;i++){
       a=fgetc(fi);
       if(a=='A')
         con1++;
       else
         con2++;
    }
    if(con1>con2)
      fprintf(fout,"Anton");
    else
      if(con1<con2)
        fprintf(fout,"Danik");
      else
        fprintf(fout,"Friendship");
    //fclose(fi);
  //  fclose(fout);
    return 0;
}