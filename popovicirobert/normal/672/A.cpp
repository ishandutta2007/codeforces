#include <cstdio>
int v[10];
int main(){
   // FILE*fi,*fout;
    int nr,cif,n,x,nrcif,aux;
   // fi=fopen("A.in" ,"r");
  //  fout=fopen("A.out" ,"w");
    scanf("%d" ,&n);
    nr=1;
    cif=0;
    while(cif<n){
        x=nr;
        nrcif=0;
        while(x>0){
            v[nrcif++]=x%10;
            x/=10;
        }
        nrcif--;
        while(nrcif>=0&&cif<n){
            cif++;
            nrcif--;
        }
        if(cif==n)
           aux=v[nrcif+1];
        nr++;
    }
    printf("%d" ,aux);
   // fclose(fi);
   // fclose(fout);
    return 0;
}