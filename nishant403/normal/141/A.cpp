#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    string a,b,c;
    cin >> a >> b >> c;
    
    int c1[26]={0},c2[26]={0};
    
    for(auto x : a) c1[x-'A']++;
    for(auto x : b) c1[x-'A']++;
    for(auto x : c) c2[x-'A']++;
    
    for(int i=0;i<26;i++) if(c1[i]!=c2[i]) {cout << "NO"; return 0;}
     cout << "YES";
    
}