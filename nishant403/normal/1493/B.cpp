#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int h,m;
string s;

void add()
{
    int hr = (s[0]-'0')*10 + s[1]-'0';
    int mn = (s[3]-'0')*10 + s[4]-'0';
    
    mn++;
   
    if(mn == m) hr++;
    
    mn%=m;
    hr%=h;
    
    s[0] = (hr/10) + '0';
    s[1] = (hr%10) + '0';
    s[3] = (mn/10) + '0';
    s[4] = (mn%10) + '0';
}

char get(char x)
{
    if(x == '2') return '5';
    else if(x == '5') return '2';
    else if(x == '8' || x == '0' || x == '1' || x == ':') return x;
    return '9';
}

bool valid()
{
    string t;
    
    for(auto x : s)
    {
        t += get(x);
        if(t.back() == '9') return 0;
    }
    
    reverse(t.begin(),t.end());
    
    int hr = (t[0]-'0')*10 + t[1]-'0';
    int mn = (t[3]-'0')*10 + t[4]-'0';
    
    if(hr >= h || mn >=m) return 0;
    
    return 1;
}

void solve()
{
   cin >> h >> m >> s;
    
   while(!valid()) add();
    
   cout << s << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}