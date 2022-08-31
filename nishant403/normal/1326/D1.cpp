#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

pii get(string & s)
{
    int n = s.length();

     vector<int> d1(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
}
    
    vector<int> d2(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
}
    
    //case 1 ; end not included
    int len = 0;
    pii res = {-1,-1};
        
    f(i,n)
    {
        int l = i - (d1[i] - 1);
        int r = i + (d1[i] - 1);
        
        if(l == 0 || r == n-1)
        {
            if(len < (r-l+1))
            {
                len = r-l+1;
                res = {l,r};
            }
        }
    }
    
    f(i,n)
    {
        int l = i - (d2[i]);
        int r = i + (d2[i] - 1);
        
        if(l == 0 || r == n-1)
        {
            if(len < (r-l+1))
            {
                len = r-l+1;
                res = {l,r};
            }
        }
    }
    
  return res;  
}


void solve()
{
   string s;
   cin >> s;
    
   int n = s.length();
   
    pii res1 = get(s);
    int len = res1.S - res1.F + 1;
    if(res1.S == -1) len = -1;
        
    int len2 = 0;
    int l = 0;
    int r = n-1;
    
    while(l<r)
    {
        if(s[l] == s[r])
        {
         l++;
         r--;
         len2+=2;
        }
        else break;
    }
    
    string rem;
    
    for(int i=l;i<=r;i++) rem+=s[i];
    
    pii go;
    go = get(rem);
    
    if(go.F != -1) len2+=go.S-go.F+1;
    
    if(len2 <= len)
    {
        for(int i=res1.F;i<=res1.S;i++) cout << s[i];
        cout << '\n';
    }
    else
    {
       for(int i=0;i<l;i++) cout << s[i];
       for(int i=go.F;i<=go.S;i++) cout << rem[i];
       for(int i=r+1;i<n;i++) cout << s[i];
        cout << '\n';
    }
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}