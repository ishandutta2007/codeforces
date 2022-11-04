#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int a[505];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int mi=INF;
    for(int i=1;i<=n;i++)
        mi=min(mi,a[i]);
    vector<int>tmp;
    int t;
    for(t=1;t*t<=mi;t++)
        if(t>=(mi-1)/(mi/t))tmp.push_back(t);
    for(int i=mi/t;i>=1;i--)
        for(int j=(mi-1)/i;j<=mi/i;j++)
            tmp.push_back(j);
    int siz=1;
    for(int i=0;i<(int)tmp.size();i++)
    {
        bool flag=1;
        for(int j=1,t=tmp[i];j<=n;j++)
            flag&=(t>=(a[j]-1)/(a[j]/t));
        if(flag)siz=max(siz,tmp[i]);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int x=(a[i]+siz)/(siz+1)*(siz+1)-a[i];
        res+=x+(a[i]-x*siz)/(siz+1);
    }
    return 0*printf("%lld",res);
}