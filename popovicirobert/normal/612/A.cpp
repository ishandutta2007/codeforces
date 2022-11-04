#include <cstdio>
char v[200];
int main(){
  //  FILE*fi,*fout;
    int i,p,n,q,a,b,j;
   // fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    scanf("%d%d%d " ,&n,&p,&q);
    for(i=0;i<n;i++)
        v[i]=fgetc(stdin);
    i=0;
    a=b=-1;
    while(i*p<=n){
        if((n-i*p)%q==0){
            a=i;
            b=(n-i*p)/q;
        }
        i++;
    }
    if(a==-1)
        printf("-1");
    else{
        printf("%d\n" ,a+b);
        int poz=0;
        for(i=0;i<a;i++){
            for(j=0;j<p;j++)
                printf("%c" ,v[j+poz]);
            poz+=p;
            printf("\n");
        }
        for(i=0;i<b;i++){
            for(j=0;j<q;j++)
                printf("%c" ,v[j+poz]);
            poz+=q;
            printf("\n");
        }
    }
    //fclose(fi);
   // fclose(fout);
    return 0;
}