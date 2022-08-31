#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 150000;
int fre[N][26];
int n;
string s;

int go(int l,int r,int c)
{
    if(l == r) 
    {
        if(s[l] == ('a' + c)) return 0;
        return 1;
    }
    
    int len = (r - l + 1)/2;
    int mid = l + len - 1;
    
    int s1 = fre[mid][c];
    if(l > 0) s1-=fre[l-1][c];
    
    int s2 = fre[r][c] - fre[mid][c];
    
    return min(len - s1 + go(mid+1,r,c+1), len - s2 + go(l,mid,c+1));
}

void solve()
{
    cin >> n;
    cin >> s;
    
    f(i,n) f(j,26) fre[i][j] = 0;
    f(i,n) fre[i][s[i]-'a']++;
    f(i,26) f(j,n-1) fre[j+1][i]+=fre[j][i];
   
    cout << go(0,n-1,0) << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}