#include <cstdio>
#include <algorithm>
int lin[100009],col[100009];
int main(){
    int i,n,nrl,nrc,m,l,c;
    long long con;
    scanf("%d%d" ,&n,&m);
    con=n;
    con=con*con;
    nrc=0;
    nrl=0;
    for(i=1;i<=m;i++){
        scanf("%d%d" ,&l,&c);
        if(lin[l]==0){
           lin[l]=1;
           nrl++;
           con-=n;
           con+=nrc;
        }
        if(col[c]==0){
            col[c]=1;
            nrc++;
            con-=n;
            con+=nrl;
        }
        printf("%I64d " ,con);
    }
    return 0;
}