#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
signed main()
{
 fast;
 int n,k;

 cin >> n >> k;
    
   int a[n];
    
    multiset<int> s;
    set<int> ss;
    
    for(int i=0,j=0;j<n;j++)
    {
        cin >> a[j];
        
        s.insert(a[j]);        
        ss.insert(a[j]);
        
        
        while (s.count(a[i]) >= 2)    
            s.erase(s.find(a[i++]));         
        
        if(ss.size()==k) { cout << i+1 << " " << j+1; return 0; }          
    }
       
    cout << "-1 -1";

}