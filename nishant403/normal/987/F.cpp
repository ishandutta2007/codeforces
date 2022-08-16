#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int LN = 22;
const int N = (1LL<<LN) + 10;

int a[N];
int sos[N];
int n;

pii dsu[N];

int con[N];

int find(int x)
{
    if(dsu[x].F == x) return x;
    return dsu[x].F = find(dsu[x].F);
}

void merge(int u,int v)
{
    int p = find(u);
    int q = find(v);
    
    if(p == q) return;
    
    if(dsu[p].S > dsu[q].S) swap(p,q);
    
    dsu[q].S += dsu[p].S;
    dsu[p].F = q;
}

int used[N];

signed main()
{
    fast;
    
    int n,m,x;
    cin >> n >> m;
    
    f(i,m) cin >> a[i];
    
    int tot = (1<<n);
    int mask = tot - 1;
    
    f(i,tot) dsu[i] = {i,1};
    
    f(i,m) sos[a[i]]++;
    
    f(i,n) f(j,tot)
        if(j & (1<<i)) sos[j] += sos[j^(1<<i)];
        
    f(i,tot)
        if(sos[i] > 0 && sos[i^mask] > 0) 
    {
        merge(i,i^mask);
        con[i] = 1;
        con[i^mask] = 1;
    }
        
    for(int i=tot-1;i>=1;i--)
    {
        if(sos[i] == 0) continue;
        
        f(j,n) if( (i & (1<<j)) == 0 && con[i^(1LL<<j)])
        {
            con[i] = 1;
            merge(i,i^(1LL<<j));
        }
    }
    
    int res = 0;
    f(i,m) used[find(a[i])] = 1;
    f(i,tot) res += used[i];
    cout << res;
}