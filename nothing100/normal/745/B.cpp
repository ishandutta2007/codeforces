#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
char ch[1010][1010];
int n,m,sum,a[1010][1010];
int main(){
    scanf("%d%d\n",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            scanf("%c",&ch[i][j]);
            if (ch[i][j]=='X'){
                a[i][j]=1;
                sum++;
            }
        }
        scanf("\n");
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
                a[i][j]=a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
                //printf("%d",a[i][j]);
        }
        //printf("\n");
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (ch[i][j]=='X'){
                int l=i,r=j;
                while (ch[l+1][j]=='X') l++;
                while (ch[i][r+1]=='X') r++;
                //printf("%d %d %d %d",i,j,l,r);
                //printf(" %d %d\n",a[l][r]+a[i-1][j-1]-a[i-1][r]-a[l][j-1],sum);
                if ((a[l][r]+a[i-1][j-1]-a[i-1][r]-a[l][j-1]==sum)&&((a[l][r]+a[i-1][j-1]-a[i-1][r]-a[l][j-1])==((l-i+1)*(r-j+1)))) printf("YES\n");
                else printf("NO\n");
                return 0;
            }
}