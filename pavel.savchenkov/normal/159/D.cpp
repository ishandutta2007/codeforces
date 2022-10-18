#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#define i64 long long
#define forn(i,n) for (int i=0;i<(int)n;i++)

using namespace std;
i64 p[3100];
i64 prefhash[3100];
i64 suffhash[3100];
char s[3100];
int len;
i64 dpref[3100];

i64 get_pref_hash(int l,int r)
{
    if (l == 0) return prefhash[r] * p[len];
    return ( prefhash[r] - prefhash[l-1] ) * p[len-l];
}

i64 get_suff_hash(int l,int r)
{
    if (r == len-1) return suffhash[l] * p[len];
    return ( suffhash[l] - suffhash[r + 1] ) * p[r + 1];
}

bool isPol(int l,int r)
{
    int  m = l + (r - l) / 2;
    i64 h1,h2;
    
    if ( ((r - l)&1) )
    {
     h1 = get_pref_hash(l,m);
     h2 = get_suff_hash(m+1,r);
    } else
    {
     h1 = get_pref_hash(l,m);
     h2 = get_suff_hash(m,r);
    }
    return (h1 == h2);
}

void build()
{
  dpref[0] = 1;
  
  for (int i=1; i<len; i++)
  {
    dpref[i] = dpref[i-1];
    for (int l=0;l<=i;l++)
        dpref[i] += isPol(l,i);
  }
  
}

int main() {
  p[0] = 1;
  gets(s);
  len = (int)strlen(s);
  for (int i=1; i<=3000; i++) p[i] = p[i-1]*29ll;
  prefhash[0] = s[0] - 'a' + 1;
  for (int i=1; i<len; i++) prefhash[i] = prefhash[i-1] + p[i]*(s[i] - 'a' + 1);
  suffhash[len - 1] = s[len - 1] - 'a' + 1;
  for (int i=len-2; i>=0; i--) suffhash[i] = suffhash[i+1] + p[len-i-1]*(s[i] - 'a' + 1);
  
  build();
  i64 res = 0;
  
  for (int l=1; l<len; l++)
    for (int r=l; r<len; r++)
    {
        if (isPol(l,r)) res += dpref[l - 1];
    }
    
  cout << res << endl;
  return 0;
}