#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    string s;
    cin >> s;
    
    int cur =s[0];
    int str = 1;
    
    for(int i=1;i<s.length();i++)
    {
     if(cur==s[i]) str++;
     else str=1; 
        
       cur=s[i];
        if(str>=7){cout << "YES"; return 0;}
    }
    
    cout << "NO";
}