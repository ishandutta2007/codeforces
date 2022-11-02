#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1000000000
#define LL long long
using namespace std;
int n,b[100010][2],col[100010],num,sum[100010],ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++) scanf("%d%d",&b[i][0],&b[i][1]);
    for (int i=1;i<=n;i++) scanf("%d",&col[i]);
    for (int i=1;i<n;i++)
    if (col[b[i][0]]!=col[b[i][1]]){
        num++;
        sum[b[i][0]]++;
        sum[b[i][1]]++;
    }
    for (int i=1;i<=n;i++)
    if (sum[i]==num) ans=i;
    if (ans){
        printf("YES\n%d\n",ans);
    }
    else printf("NO\n");
}