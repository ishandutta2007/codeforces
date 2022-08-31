#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

int query(int x,int y)
{
    
    cout << "? " << x+1 << ' ' << y+1 << endl;
    cin >> x;
    assert(x != -1);
    return x;
}

const int N = 1e4 + 10;
int res[N];
int vis[N];
int n;

void solve(vector<int> & id)
{
    if(id.size() == 0) return;
    
    if(id.size() == 1)
    {
        for(int i=1;i<=n;i++)
            if(vis[i] == 0) res[id[0]] = i;
            
        return;
    }
    
    vi nex;
    
    if(id.size() % 2 == 1) 
    {
        nex.pb(id.back());
        id.pop_back();
    }
    
    for(int i=0;i<id.size();i+=2)
    {
        int a1 = query(id[i],id[i+1]);
        int a2 = query(id[i+1],id[i]);
        
        if(a1 > a2) 
        {
            res[id[i]] = a1;
            vis[a1] = 1;
            nex.pb(id[i+1]);
        }
        else 
        {
            res[id[i+1]] = a2;
            vis[a2] = 1;
            nex.pb(id[i]);
        }
    }
    
    solve(nex);
}
    
signed main()
{
     cin >> n;
      
    vector<int> id;
    f(i,n) id.pb(i);
    solve(id);
    
    cout << "! ";
    f(i,n) cout << res[i] <<' ';
    cout << endl;
}