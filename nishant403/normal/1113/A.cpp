#include <bits/stdc++.h>
using namespace std;
#define f(n) for(i=0;i<n;i++)
typedef long long ll;

int main()
{
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 
 int i,ans=0,tot;
 int n,v;

 cin >> n >> v;
 
 tot=n-1;
 
 if(v >= tot)
 {
     cout << tot;
}
else
{
 cout << v+ ( (tot-v)*(tot-v+3) )/2;    
    
}
 
 
 
 
 
 
 
 return 0;
}