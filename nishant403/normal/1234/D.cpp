#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 1e5+10;
bitset<26> seg[2*N];

int n,q,t,l,r;
char c;
string s;

void upd(int id,int val)
{
  id+=n;
  seg[id] = (1<<val);       
  for(;id>1;id>>=1) seg[id>>1] = seg[id]|seg[id^1];  
}

int query(int l,int r)
{
 r++;
    
 bitset<26> ans = 0;
    
 for(l+=n,r+=n;l<r;l>>=1,r>>=1)
 {
  if(l&1) ans=ans|seg[l++];
  if(r&1) ans=ans|seg[--r]; 
 }
    
 return ans.count();        
}


void solve()
{
  cin >> s;
    
  n = s.length();
    
  f(i,n) seg[i+n] = 1<<(s[i]-'a');
    
  for(int i=n-1;i;i--) seg[i] = seg[i<<1]|seg[i<<1^1];
    
  cin >> q;
    
  while(q--)
  {
   cin >> t >> l;
      
   if(t==1)
   {
     cin >> c;
     upd(l-1,c-'a');
   }
   else
   {
    cin >> r;
    cout << query(l-1,r-1) << '\n';
   }
  }
       
}

int main()
{
    fast;
    solve();
}