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
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=200007,pot=1<<18;

int a[N];

int seg[2][2*pot+7];

vector<int>X[N];
vector<pair<int,int>>C[N];

void ins(int v,int x,int s)
{
    v+=pot-1;
    seg[s][v]=max(seg[s][v],x);
    while(v>1)
    {
        v/=2;
        seg[s][v]=max(seg[s][2*v],seg[s][2*v+1]);
    }
}
int que(int v,int a,int b,int l,int r,int s)
{
    if(a<=l&&b>=r) return seg[s][v];
    if(r<a||l>b) return 0;
    return max(que(2*v,a,b,l,(l+r)/2,s),que(2*v+1,a,b,(l+r)/2+1,r,s));
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<pair<int,int>>V;
        for(int i=n;i>0;i--)
        {
            while(sz(V)>0&&V.back().st<a[i])
            {
                C[i].pb(V.back());
                V.pop_back();
            }
            V.pb({a[i],i});
        }
        V.clear();
        for(int i=1;i<=n;i++)
        {
        	for(auto x:C[i])
        	{
        		int t=que(1,1,x.st-1,1,pot,1);
        		X[t].pb(x.nd);
        	//	cout<<t<<" "<<x.nd<<endl;
        	}
      	    while(sz(V)>0&&V.back().st>a[i])
            {
                ins(V.back().st,V.back().nd,1);
                V.pop_back();
            }
            V.pb({a[i],i});	
        }
        for(int i=1;i<=n;i++)
        {
        	C[i].clear();
        	a[i]=n-a[i]+1;
        }
        V.clear();
        for(int i=n;i>0;i--)
        {
            while(sz(V)>0&&V.back().st<a[i])
            {
                C[i].pb(V.back());
                V.pop_back();
            }
            V.pb({a[i],i});
        }
        V.clear();
        for(int i=1;i<=n;i++)
        {
        	for(auto x:C[i])
        	{
        		int t=que(1,1,x.st-1,1,pot,0);
        		X[t].pb(x.nd);
        	//	cout<<t<<" "<<x.nd<<endl;
        	}
      	    while(sz(V)>0&&V.back().st>a[i])
            {
                ins(V.back().st,V.back().nd,0);
                V.pop_back();
            }
            V.pb({a[i],i});	
        }
        int ans=0,j=n+1;
        for(int i=n;i>0;i--)
        {
            for(auto x:X[i]) j=min(j,x);
            ans+=j-i;
        }
        cout<<ans;
    }

    return 0;
}