#include <bits/stdc++.h>
using namespace std;
  
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1005;

struct dsu
{
    int par;
    int sz;
};

struct mapper
{
    gp_hash_table<int,int> x_max,x_min,y_max,y_min;
};

dsu node[N];
pii a[N];
int n;

int find(int x)
{
    if(node[x].par == x) return x;
    return node[x].par = find(node[x].par);
}

void merge(int x,int y)
{
    int a = find(x);
    int b = find(y);
    
    if(a == b) return;
    
    if(node[a].sz > node[b].sz) swap(a,b);
    
    node[a].par = b;
    node[b].sz += node[a].sz;
}

void reset()
{
    f(i,n)
    {
        node[i].par = i;
        node[i].sz = 1;
    }
}

bool check(int t)
{
    reset();
    
    f(i,n) f(j,n)
    if(a[i].F == a[j].F) 
    {
       int dis = abs(a[i].S - a[j].S);
       if(dis <= t) merge(i,j);
    }
    else if(a[i].S == a[j].S) 
    {
       int dis = abs(a[i].F - a[j].F);
       if(dis <= t) merge(i,j);
    }
    
    set<int> cnt2;
    f(i,n) cnt2.insert(find(i));
    
    int sz = (int)cnt2.size();
    
    if(sz > 4) return 0;
    if(sz < 2) return 1;
    
    vi cnt;
    for(auto x : cnt2) cnt.pb(x);
    
    mapper go[sz];
    
    f(i,n) 
    {
        int id = find(i);
        
        for(int j=0;j<sz;j++)
        {
            if(cnt[j] == id)
            {
               if(go[j].x_max.find(a[i].S) == go[j].x_max.end())
               {
                   go[j].x_max[a[i].S] = a[i].F;
                   go[j].x_min[a[i].S] = a[i].F;
               }
               else
               {
                   go[j].x_max[a[i].S] = max(a[i].F,go[j].x_max[a[i].S]);
                   go[j].x_min[a[i].S] = min(a[i].F,go[j].x_min[a[i].S]);
               }
                
               if(go[j].y_max.find(a[i].F) == go[j].y_max.end())
               {
                   go[j].y_max[a[i].F] = a[i].S;
                   go[j].y_min[a[i].F] = a[i].S;
               }
               else
               {
                   go[j].y_max[a[i].F] = max(a[i].S,go[j].y_max[a[i].F]);
                   go[j].y_min[a[i].F] = min(a[i].S,go[j].y_min[a[i].F]);
               } 
            }
        }
    }
    
    f(i,n) f(j,n)
    {
        int ptx = a[i].F;
        int pty = a[j].S;
        int flag = 1;
        
        for(int k=0;k<sz;k++)
        {
            int dd = (t + 1);
            
            if(go[k].x_max.find(pty) != go[k].x_max.end())
            {
                dd = min(dd,abs(go[k].x_max[pty] - ptx));
                dd = min(dd,abs(go[k].x_min[pty] - ptx));
            }
            
            if(go[k].y_max.find(ptx) != go[k].y_max.end())
            {
                dd = min(dd,abs(go[k].y_max[ptx] - pty));
                dd = min(dd,abs(go[k].y_min[ptx] - pty));
            }
            
            if(dd > t)
            {
                flag = 0;
                break;
            }
        }
        
        if(flag) return 1;
    }
    
    if(sz == 2)
    {
        f(i,n) f(j,n) if(find(i) != find(j))
        {
            if(a[i].F != a[j].F && a[i].S != a[j].S) continue;
            if(abs(a[i].F - a[j].F) + abs(a[i].S - a[j].S) <= t + t) return 1;
        }
    }
    
    return 0;
}

signed main()
{
    fast;
    
    cin >> n;
    
    f(i,n) cin >> a[i].F >> a[i].S;
 
    int l = 0;
    int r = 2e9;
    int res = -1;
    
    while(l <= r)
    {
        int mid = (l + r)/2;
        
        if(check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << res;
}