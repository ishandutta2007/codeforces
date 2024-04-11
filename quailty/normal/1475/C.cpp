#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int a[MAXN],b[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%*d%*d%d",&k);
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=k;i++)
            scanf("%d",&b[i]);
        ll res=1LL*k*(k-1)/2;
        map<int,int> cnt_a,cnt_b;
        for(int i=1;i<=k;i++)
        {
            res-=cnt_a[a[i]];
            cnt_a[a[i]]++;
            res-=cnt_b[b[i]];
            cnt_b[b[i]]++;
        }
        map<pair<int,int>,int> cnt_ab;
        for(int i=1;i<=k;i++)
        {
            res+=cnt_ab[{a[i],b[i]}];
            cnt_ab[{a[i],b[i]}]++;
        }
        printf("%lld\n",res);
    }
    return 0;
}