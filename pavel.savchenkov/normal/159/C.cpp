#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <memory.h>
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)

using namespace std;
char s[2005000];
int in[30][200500];
int t[30][200500];
int sz[30];
int k,n;
char str[200];

void upd(char c,int i,int d)
{
    c = c - 'a';
    for (; i<sz[c]; i = i|(i+1) )
        t[c][i] += d;
}

int sum(char c,int r)
{
    if (r < 0) return 0;
    c = c - 'a';
    int res = 0;
    for (; r>=0; r = (r&(r+1)) - 1)
        res += t[c][r];
    return res;
}

void init(char *str)
{
    memset(sz,0,sizeof(sz));
    int len = (int)strlen(str);
    for (int start = 0; start<=len*(k-1); start += len)
        for (int i = 0; i<len; i++)
             { 
                 s[start + i] = str[i]; int c = str[i] - 'a'; 
                 in[c][sz[c]] = start + i; 
                 t[c][sz[c]] = 0; sz[c]++; 
             }
    s[len*k] = '\n';
}

int get_new_num(char c,int old_ind)
{
    return old_ind - sum(c,old_ind - 1);
}

int get(char c,int p)
{
    c = c - 'a';
    int l = 0; int r = sz[c] - 1;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if ( s[in[c][m]] == '^')
        {
            int np = m - sum(c+'a',m-1);
            if (np >= p) r = m - 1; else l = m + 1;
            continue;
        }
        int np = get_new_num(c+'a',m) + 1;
        if (np == p) return m;
        if (np < p) l = m + 1; else r = m - 1;
    }
    
    for (int i=l; i<=r; i++)
        if (s[in[c][i]] != '^' && get_new_num(c+'a',i) + 1 == p) return i;
}


int main() {
  scanf("%d\n",&k);
  char str[200];
  gets(str);      
      
  init(str);    
  scanf("%d",&n);
  forn(i,n)
  {
      int p; char c;
      scanf("%d %c",&p,&c);
      int ind = get(c,p);
      s[in[c-'a'][ind]] = '^';
      upd(c,ind,1);
  }
  
  
  int len = (int)strlen(s);
  for (int i=0; i<len; i++)
      if (s[i] != '^')  putchar(s[i]);

  return 0;
}