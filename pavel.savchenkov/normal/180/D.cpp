#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
int c[250];
char s[6000];
char r[6000];
int k[250];

int main() {
//freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(c,0,sizeof(c));
  gets(s);
  int n = (int)strlen(s);
  for (int i=0; s[i]; i++)
    c[s[i]]++, k[s[i]]++;
  gets(s);
  int m = (int)strlen(s);
  
  bool ok = 0;
  forn(i,n) r[i] = 'a' - 1;
  
  for (int i=0; s[i]; i++)
    if (c[s[i]] != 0) c[s[i]]--, r[i] = s[i]; else
    {
        foran(j,s[i]+1,'z'+1)
            if (c[j] != 0) 
            { 
                r[i] = j;  c[j]--;
                ok = 1;
                for (int k=i+1; k < n; k++)
                {
                    foran(x,'a','z'+1)
                        if (c[x] != 0) { r[k] = x; c[x]--; break; }
                }
                break; 
            }
        if (ok) break;

        int j = i - 1;
        for (; j>=0; j--)
        {
                foran(k,s[j]+1,'z'+1)
                    if (c[k] != 0) { r[j] = k; ok = 1; c[k]--; break; }
                c[s[j]]++;
                if (ok) break; else r[j] = 'a' - 1;
        }
        
        if (!ok) { puts("-1"); return 0; }
        break;
    }
  
  if (!ok && n <= m) 
  { 
        int j = n - 1;
        for (; j>=0; j--)
        {
                c[s[j]]++;
                foran(k,s[j]+1,'z'+1)
                    if (c[k] != 0) { r[j] = k; ok = 1; c[k]--; break; }
                if (ok) break; else r[j] = 'a' - 1;
        }
      
      if (!ok) { puts("-1");  return 0; } 
  }
  
  for (int i = n - 1; i>=0; i--)
    if (r[i] >='a' && r[i] <= 'z') break;
    else
    {
        for (int j='z'; j>='a'; j--)
            if (c[j] != 0) { r[i] = j; c[j]--; break; }
    }       
    
  forn(i,n) putchar(r[i]);
  
  return 0;
}