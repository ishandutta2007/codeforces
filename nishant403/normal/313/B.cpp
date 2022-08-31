#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
Fast;    

string s;
getline(cin,s);
    
    int n =  s.length();
    
 int pref[n+1];   
    
  pref[0] = 0;  
    
f(i,n-1) pref[i+1] = pref[i] + (s[i]==s[i+1]);    
 pref[n] = pref[n-1];
    
int m,a,b;
    cin >> m;
    while(m--)
    {
        cin >> a >> b;
        cout << pref[b-1] - pref[a-1] << "\n";    
    }
    
    
}