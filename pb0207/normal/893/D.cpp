#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,d;

int a[N];

ll pre[N],f[N];

int ans;
ll s;


int main() {
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    for (int i=1;i<=n;++i) {
        pre[i]=pre[i-1]+a[i];
        if (pre[i]>d) return puts("-1"),0;
    }
    f[n]=pre[n];
    for (int i=n-1;i>=1;--i) f[i]=max(pre[i],f[i+1]);
    for (int i=1;i<=n;++i) f[i]=d-f[i];
    ans=0,s=0;
    for (int i=1;i<=n;++i) if (a[i]==0 && pre[i]+s<0) {
        ans++;
        s=f[i];
        if (pre[i]+s<0) return puts("-1"),0;
    }
    printf("%d\n",ans);
    return 0;
}