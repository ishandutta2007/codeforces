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


int ans[1000001];

signed main()
{
Fast;    

string s;
getline(cin,s);
    
int l = 1;
int r = s.length();   
    
for(int i=1;i<=s.length();i++)
{
 if(s[i-1]=='l') ans[r--] = i;
 else ans[l++] = i;
}
    
for(int i=1;i<=s.length();i++)
    cout << ans[i] << "\n";
    
}