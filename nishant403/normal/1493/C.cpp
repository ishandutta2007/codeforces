#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n,k;
string s;
int fre[26];
int sum;

void change(char c,int sn)
{
    sum -= (k - fre[c - 'a'])%k;
    fre[c - 'a']+=sn + k;
    fre[c - 'a']%=k;
    sum += (k - fre[c - 'a'])%k;
}

void solve()
{
   sum = 0;
   f(i,26) fre[i] = 0;
    
   cin >> n >> k >> s;
    
   if(n % k != 0)
   {
       cout << -1 << '\n';
       return;
   }
   
   for(auto x : s) change(x,1);
    
   if(sum == 0)
   {
       cout << s << '\n';
       return;
   }
    
   for(int i=n-1;i>=0;i--)
   {
       change(s[i],-1);
           
       for(char c=s[i]+1;c<='z';c++)
       {
           change(c,1);
           
           if(n-i-1 >= sum)
           {
               f(j,i) cout << s[j];
               cout << c;
               f(j,n-i-1-sum) cout << 'a';
               f(j,26) f(v,(k-fre[j])%k) cout << (char)('a' + j);
               cout << '\n';
               return;
           }
           
           change(c,-1);
       }
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