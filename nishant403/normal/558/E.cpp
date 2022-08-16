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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 1e5 + 10;

struct seg
{
    int st[4*N];
    int lazy[4*N];
    
    //1 set
    //2 reset
    
    void push(int node,int ss,int se)
    {
        if(lazy[node] == 0) return;
        
        if(lazy[node] == 1) st[node] = se - ss + 1;
        else st[node] = 0;
        
        if(ss != se)
            lazy[node*2+1] = lazy[node*2+2] = lazy[node];
        
        lazy[node] = 0;
    }
    
    void update(int node,int ss,int se,int l,int r,int v)
    {
        push(node,ss,se);
        
        if(ss > r || se < l) return;
        
        if(l <= ss && se <= r)
        {
            if(v == 0) lazy[node] = 2;
            else lazy[node] = 1;
            
            push(node,ss,se);
            return;
        }
        
        int mid = (ss + se)/2;
        
        update(node*2+1,ss,mid,l,r,v);
        update(node*2+2,mid+1,se,l,r,v);
        st[node] = st[node*2+1] + st[node*2+2];
    }
    
    int query(int node,int ss,int se,int l,int r)
    {
        push(node,ss,se);
        
        if(ss > r || se < l) return 0;
        
        if(l <= ss && se <= r) return st[node];
        
        int mid = (ss + se)/2;
        
        return query(node*2+1,ss,mid,l,r) + query(node*2+2,mid+1,se,l,r);
    }
};

seg go[26];

int n,q;
string s;

int fre[26];

void solve()
{
   cin >> n >> q >> s;
   f(i,n) go[s[i] - 'a'].update(0,0,n-1,i,i,1); 
    
   int x,y,z; 
    
   while(q--)
   {
       cin >> x >> y >> z;
       x--,y--;
       
       f(i,26)
       {
           fre[i] = go[i].query(0,0,n-1,x,y);
           go[i].update(0,0,n-1,x,y,0);
       }
       
       if(z == 1) 
       {
           f(i,26)
           {
               go[i].update(0,0,n-1,x,x + fre[i] - 1,1);
               x += fre[i];
           }
       }
       else
       {
           for(int i=25;i>=0;i--)
           {
               go[i].update(0,0,n-1,x,x + fre[i] - 1,1);
               x += fre[i];
           }
       }

   }
    
    f(i,n) f(j,26)
           if(go[j].query(0,0,n-1,i,i) == 1) cout << ((char)('a' + j));
       cout << '\n';
       
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}