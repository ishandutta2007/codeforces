#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define ull unsigned long long
using namespace std;
int n;
const int maxn = 5e5 + 5;
const int mod = 998244353;
const int mod2 = 1e9 + 7;
int ha[maxn];
int ha2[maxn];
int pw[maxn];
int sed = 131;
int last[maxn];
int pre[maxn];
int a[maxn];
int cnt[maxn];
#define P(a,b)  (ll)a*mod+b
unordered_map<ll,int> mp;
int main()
{
    pw[0] = 1;
    fors(i,1,maxn) pw[i] = (ll)pw[i-1]*sed%mod;
    scanf("%d", &n);
    fors(i,1,n+1){
        scanf("%d", &a[i]);
        ha[i] = ha[i-1];
        ha[i] = (ha[i-1] - (ll)cnt[a[i]]*pw[a[i]])%mod;

        ha2[i] = ha2[i-1];
        ha2[i] = (ha2[i-1] - (ll)cnt[a[i]]*pw[a[i]])%mod2;

        cnt[a[i]]=(cnt[a[i]]+1)%3;

        ha[i] = (ha[i] + (ll)cnt[a[i]]*pw[a[i]])%mod;
        ha[i]= (ha[i] + mod)%mod;

        ha2[i] = (ha2[i] + (ll)cnt[a[i]]*pw[a[i]])%mod2;
        ha2[i] = (ha2[i]+mod2)%mod2;

        pre[i] = last[a[i]];
        last[a[i]] = i;
    }

    mp.clear();
    mp[P(0,0)] = 1;
    int p = 0;
    ll ans = 0;
    fors(i,1,n+1){
        int pp = pre[i];
        pp = pre[pp];
        pp = pre[pp];
        //cout<<"i:"<<i<<" pp:"<<pp<<endl;
        while(p < pp) mp[P(ha[p], ha2[p])]--, p++;
        ans += mp[P(ha[i], ha2[i])];
        mp[P(ha[i], ha2[i])]++;
    }cout<<ans<<endl;
}