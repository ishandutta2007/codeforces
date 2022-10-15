
 // luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N = 105;
char a[N][N],b[N][N];
int main(){
    int n,m;register int i,j;
    scanf("%d %d\n",&m,&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)scanf("%c",&b[i][j]);
        if(i<n)scanf("\n");
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
        a[n-i+1][j]=b[i][j];
    }
    for(i=1;i<=m;i++){
        for(j=n;j>=1;j--){
            putchar(a[j][i]);
            putchar(a[j][i]);
        }
        putchar('\n');
        for(j=n;j>=1;j--){
            putchar(a[j][i]);
            putchar(a[j][i]);
        }
        putchar('\n');
    }
    return 0;
}