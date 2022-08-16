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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 2e5 + 100;
const int BLK = 200;

vector<int> g[N] ;
vector<pii> g2[N];
int mp[N];

vector<int> cmp;

void solve()
{
	cmp.clear();
	
	int n;
	cin >> n;
	
   	int x,y;
   	
   	f(i,n)
   	{
   		g[i].clear();
   		
   		cin >> x;
   		
   		f(j,x)
   		{
   			cin >> y;
   			g[i].pb(y);	
   			cmp.pb(y);
   		}	
   	}
   	
   	sort(all(cmp));
   	
   	f(i,n)
   		for(auto & x : g[i])
   			x = lower_bound(all(cmp),x) - cmp.begin();
   	
   	int sz = cmp.size();
   	f(i,sz+5) mp[i] = 0;
   	f(i,sz+5) g2[i].clear();
   	
   	f(i,n)
   	{
   		if((int)g[i].size() > BLK)
   		{
   			for(auto x : g[i]) mp[x] = 1;
   			
   			f(j,n)
   			{
   				if(j == i) continue;
   				
   				int cc = 0;
   				for(auto x : g[j]) cc += mp[x];
   				
   				if(cc > 1)
   				{
   					cout << i + 1 << ' ' << j + 1 << '\n';
   					return;
   				}
   			}
   			
   			for(auto x : g[i]) mp[x] = 0;
   			
   			g[i].clear();
   		}
   	}
   	
   	f(i,n)
   	{
   		for(auto x : g[i])
   			for(auto y : g[i])
   			  if(x < y) g2[x].pb({y,i+1});
   	}
   	
   	f(i,sz)
   	{
   		for(auto x : g2[i])
   		{
   			if(mp[x.F] != 0)
   			{
   				cout << mp[x.F] << ' ' << x.S << '\n';
   				return;
   			} 
   			
   			mp[x.F] = x.S;
   		}
   		
   		for(auto x : g2[i]) mp[x.F] = 0;
   	}
   	
   	cout << -1 << '\n';
   
}

signed main()
{
    fast;
    
    int t;
    
    cin >> t;
    
    while(t--)
    
    solve();
}