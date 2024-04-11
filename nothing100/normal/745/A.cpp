#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
char a[100][100],l,ans;
int compare(int x,int y){
    for (int i=0;i<l;i++)
    if (a[x][i]!=a[y][i]) return 0;
    return 1;
}
int main(){
    scanf("%s",&a[0]);
    l=strlen(a[0]);
    ans=1;
    for (int i=0;i<l-1;i++){
        a[i+1][0]=a[i][l-1];
        for (int j=0;j<l-1;j++) a[i+1][j+1]=a[i][j];
        int bo=1;
        for (int j=0;j<=i;j++) if (compare(i+1,j)) bo=0;
        ans+=bo;
    }
    printf("%d\n",ans);
    return 0;
}