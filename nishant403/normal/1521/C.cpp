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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

int ask(int t,int i,int j,int x)
{
    cout << "? " << t << ' '<< i + 1 << ' ' << j + 1<< ' ' << x << endl;
    cin >> x;
    
    assert(x != -1);
    
    return x;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> res(n,-1);
    
    int pos = -1;
    
    for(int i=0;i<n;i+=2)
    {
        int mn = ask(2,i,(i+1)%n,1);
        
        if(mn == 1)
        {
            pos = i;
            break;
        }
        
        if(mn == 2)
        {
            if(ask(2,(i+1)%n,i,1) == 1)
            {
                pos = (i+1)%n;
                break;
            }
        }
    }
    
    assert(pos != -1);
    
    res[pos] = 1;
    
    f(i,n) if(i != pos)
        res[i] = ask(1,pos,i,n-1);
    
    //print
    
    cout << "! " ;
    f(i,n) cout << res[i] << ' ';
    cout << endl;
}
    

signed main()
{
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}