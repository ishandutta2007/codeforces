#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mp make_pair
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=300007,pot=1<<19;

int seg[2*pot+7];
int que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return inf;
    if(a<=l&&b>=r) return seg[v];
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}

vector<pair<int,pair<int,int>>>Z[N];
int ans[N];
bool cmp(pair<int,pair<int,int>>l,pair<int,pair<int,int>>r)
{
    return l.st<r.st;
}
bool cmp1(pair<int,pair<int,int>>l,pair<int,pair<int,int>>r)
{
    return l.nd.st>r.nd.st;
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
        int n,q,k;
        cin>>n>>q>>k;
        for(int i=1;i<=pot;i++) seg[i+pot-1]=inf;
        for(int i=1;i<=n;i++) cin>>seg[i+pot-1];
        for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin>>l>>r;
            int L=l+((r-l)/k)*k;
            Z[l+1].pb({L,{seg[l+pot-1],i}});
            ans[i]=seg[l+pot-1];
        }
        for(int j=n-k+1;j>n-2*k+1;j--)
        {
            vector<pair<int,pair<int,int>>>Q;
            Q.pb({-inf,{j+k,0}});
            for(int i=j;i>0;i-=k)
            {
                int x=que(1,i,i+k-1,1,pot);
                while(Q.back().st>=x) Q.pop_back();
                Q.pb({x,{i,Q.back().nd.nd+(Q.back().nd.st-i)/k*x}});
                //cout<<"XD"<<i<<endl;
               // for(auto x:Q) cout<<x.st<<" "<<x.nd.st<<" "<<x.nd.nd<<endl;
                for(auto x:Z[i])
                {
                    if(x.st<i) continue;
                    Q.pb({inf,{0,Q.back().nd.nd}});
                    pair<int,pair<int,int>>p=*--lower_bound(all(Q),mp(x.nd.st,mp(inf,inf)),cmp);
                 //   cout<<x.st<<endl;
                //    cout<<p.st<<" "<<p.nd.st<<" "<<p.nd.nd<<endl;
                    if(p.st!=inf) ans[x.nd.nd]+=(min(x.st+1,p.nd.st)-i)/k*x.nd.st;
                    pair<int,pair<int,int>>p1=*(lower_bound(all(Q),mp(inf,mp(x.st,inf)),cmp1));
                    if(p.nd.nd-p1.nd.nd>=0)
                    {
                        ans[x.nd.nd]+=p.nd.nd-p1.nd.nd;
                        ans[x.nd.nd]+=p1.st*(x.st+1-p1.nd.st)/k;
                    }
                    Q.pop_back();
                }
            }
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}