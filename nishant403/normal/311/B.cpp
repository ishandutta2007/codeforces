#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int INF = 1e18;

struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};

struct ConvexHullDynamic
{
    deque<line> dq;
    
    void addLine(int a, int b) //Add ax + b in logN time
    {
        line cur = {a,b};
        while(dq.size() >= 2 && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1])) dq.pop_front();
        dq.push_front(cur);
    }
 
    int getBest(int x)
    {
        if(dq.empty()) return INF;
        while(dq.size() >= 2 && dq.back().eval(x) >= dq[(int)dq.size()-2].eval(x)) dq.pop_back(); 
        return dq.back().eval(x); 
    }
};

const int N = 1e5 + 10;
int d[N];
int d_pref[N];
pair<int,pii> go[N];
int n,m,p;

signed main()
{
    fast;
    
    cin >> n >> m >> p;
    f(i,n-1) cin >> d[i];
    f(i,m) cin >> go[i].S.F >> go[i].S.S;
    
    f(i,m) go[i].S.F--;
    f(i,n-1) d_pref[i] = d[i];
    f(i,n-2) d_pref[i+1]+=d_pref[i];
    
    vi vals;
    
    f(i,m)
    {
        int tt = go[i].S.S;
        if(go[i].S.F != 0) tt-=d_pref[go[i].S.F-1];
        go[i].F = tt;
        vals.pb(tt);
    }
    
    sort(go,go+m);
    sort(vals.begin(),vals.end());
    vals.resize(unique(vals.begin(),vals.end()) - vals.begin());
    
    vector<ConvexHullDynamic> gogo(p+1);
    gogo[0].addLine(m,0);
    
    vector<int> nex(p+1);
    
    int cnr = m;
    
    for(auto x : vals)
    {
        while(cnr > 0 && go[m-cnr].F <= x) cnr--;
        
        for(int i=1;i<=p;i++)
        {
            nex[i] = gogo[i-1].getBest(x) - (x*cnr) ;
            gogo[i].addLine(cnr,nex[i]);
        }
    }
    
    int res = nex[1];
    for(int i=1;i<=p;i++) res = min(res,nex[i]);
    f(i,m) res-=go[i].F;
    
    cout << res;
}