#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int ile[2000007];
int ans[100007];
int tab[100007];
int pref[100007];

struct Q
{
    int l,r,i;
};
int s;
bool cmp(Q L, Q R)
{
  if (L.l/s !=R.l/s) return L.l<R.l;
  return R.l/s%2 ? L.r>R.r : L.r<R.r;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,k,l,p,act=0;
        cin>>n>>m>>k;
        s=sqrt(n);
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]^tab[i];
        vector<Q>q;
        for(int i=1;i<=m;i++)
        {
            cin>>l>>p;
            q.pb({l-1,p,i});
        }
        sort(q.begin(),q.end(),cmp);
        ile[0]=1;
        l=0,p=0;
        for(auto z:q)
        {
            int L=z.l,P=z.r;
            while(p<P)
            {
                p++;
                act+=ile[pref[p]^k];
                ile[pref[p]]++;
            }
            while(l>L)
            {
                l--;
                act+=ile[pref[l]^k];
                ile[pref[l]]++;
            }
            while(p>P)
            {
                ile[pref[p]]--;
                act-=ile[pref[p]^k];
                p--;
            }
            while(l<L)
            {
                ile[pref[l]]--;
                act-=ile[pref[l]^k];
                l++;
            }
            ans[z.i]=act;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    }

    return 0;
}