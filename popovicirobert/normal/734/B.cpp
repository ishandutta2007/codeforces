#include <cstdio>
inline int getmin(int a,int b){
   if(a<b) return a;
   return b;
}
int main(){
    FILE*fi,*fout;
    int k2,k3,k5,k6,ans;
    int x;
   // fi=fopen("A.in" ,"r");
   //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d%d" ,&k2,&k3,&k5,&k6);
    ans=getmin(k2,getmin(k5,k6))*256;
    x=getmin(k2,getmin(k5,k6));
    if(x<k2)
      ans+=32*getmin(k3,k2-x);
    fprintf(fout,"%d" ,ans);
    //fclose(fi);
  //  fclose(fout);
    return 0;
}