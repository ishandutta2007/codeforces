#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>


signed main()
{
    int n,k,x,id = 0;
    
    cin >> n ;
   
   map<int,vector<int> > ans;
   map<int,int> find;
   
   cin >> x;
   
   ans[0].pb(x);
   find[x]=0;
   
   f(i,n-1)
   {
   	cin >> x;
   	
   	auto p = find.upper_bound(x);
   	
   	if(p == find.begin())
   	{
   		id++;
   		ans[id].pb(x);
   		find[x] = id;
   	}
   	else 
   	{   --p;
   	
   		ans[p->S].pb(x);
   	
   		find[x] = p->S;
   		find.erase(p->F);
   	}
   }
     
   
   for(auto x : ans)
   {
   	for(auto z : x.S) cout << z << " ";
   	cout << "\n";
   }
   
}