#include <bits/stdc++.h>

//#define int long long
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

const int N=500007;

int a[N];
vector<int>poc[N];
vector<int>kon[N];
int l[N];
int r[N];
int k[N];
int ans[N];
int cnt[N];
int ile[N];

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
        srand(time(NULL));
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=q;i++)
        {
            cin>>l[i]>>r[i];
            poc[l[i]-1].pb(i);
            kon[r[i]].pb(i);
        }
        memset(ans,-1,sizeof ans);
        for(int j=0; j<40; j++)
        {
            for(int i=1; i<=n; i++) cnt[i]=0;
            for(int i=1; i<=q; i++)
            {
                ile[i]=0;
                k[i]=a[l[i]+rand()*rand()%(r[i]-l[i]+1)];
            }
            for(int i=0; i<=n; i++)
            {
                cnt[a[i]]++;
                for(auto x:poc[i]) ile[x]-=cnt[k[x]];
                for(auto x:kon[i]) ile[x]+=cnt[k[x]];
            }
            for(int i=1; i<=q; i++)
            {
                if(ile[i]>(r[i]-l[i]+1)/2+(r[i]-l[i]+1)%2) ans[i]=ile[i];
            }
        }
        for(int i=1; i<=q; i++)
        {
            if(ans[i]==-1) cout<<1<<endl;
            else cout<<ans[i]-(r[i]-l[i]+1-ans[i])<<endl;
        }
    }

    return 0;
}