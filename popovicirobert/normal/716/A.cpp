#include <cstdio>
#define MAXN 100000
int v[MAXN+1];
int main(){
    int n,i,c,con;
    scanf("%d%d" ,&n,&c);
    for(i=1;i<=n;i++)
      scanf("%d" ,&v[i]);
    con=1;
    for(i=2;i<=n;i++){
        if(v[i]-v[i-1]<=c)
          con++;
        else
            con=1;
    }
    printf("%d" ,con);
    return 0;
}