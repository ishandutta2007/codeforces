#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void ans(vector<int> & v)
{
    cout << "! ";
    for(auto x : v) cout << x << ' ';
    cout << endl;
    
    string s;
    cin >> s;
    
    assert(s == "Correct");
}

int ask(vector<int> & q)
{
    cout <<"? ";
    cout << q.size() << ' ';
    for(auto x : q) cout << x << ' ';
    cout << endl;
    
    int v;
    cin >> v;
    return v;
}

int go2(int l,int r)
{
    int sz = r - l + 1;
    
    vector<int> v(sz);
    f(i,sz) v[i] = l + i;
    return ask(v);
}

void solve()
{
   int n,k;
    cin >> n >> k;
    
   set<int> go[k];
    
   int x,y; 
    
   f(i,k)
   {
       cin >> x;
       
       f(j,x)
       {
           cin >> y;
           go[i].insert(y);
       }
   }
    
   //step 1 : find maximum
   int mxx = go2(1,n); 
    
   //now find an index where mxx occurs
   int l = 1;
   int r = n;
   int idd = n;
    
   while(l<=r)
   {
       int mid = (l+r)/2;
       
       if(go2(l,mid) == mxx)
       {
           idd = mid;
           r = mid - 1;
       }
       else 
       {
           l = mid + 1;
       }
   }
    
   //index l contains mxx
   l = idd;
    
   vector<int> res(k);
    
   f(i,k) 
   {
       int ff = 1;
    
       for(auto x : go[i]) if(x == l) ff = 0;
       
       if(ff) res[i] = mxx;
       else
       {
           vector<int> done;
        
           for(int j=1;j<=n;j++) if(go[i].find(j) == go[i].end()) done.pb(j);
               
           res[i] = ask(done);
       }
   }
    
   ans(res); 
    
}

signed main()
{
    int t;
    cin >> t;
    
    while(t--)
    solve();
}