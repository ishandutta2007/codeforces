//HACK ME, PLEASE! ^_^
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
const i64 i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);

using namespace std;
string s1;
char s2[1000500];
int res = 0;
int next[30000][300];

int solve()
{
  gets(s2);
  if (s1[0] != s2[0] && next[0][s2[0]] == -1) return -1;
  
  int i = (s1[0] == s2[0]) ? 0 : next[0][s2[0]];
  int j = 0;
  int n = (int)strlen(s2);
  int res = 1;
  
  for (; j < n - 1; j++)
  {
    if ( next[i][s2[j + 1]] == -1) return -1;
    if ( next[i][s2[j + 1]] <= i ) res++; 
    i = next[i][s2[j + 1]];
  }
  
  return res;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(next,-1,sizeof(next));
  getline(cin, s1);
  s1 += s1;
  ford(i, s1.length() - 1)
  {
    next[i][s1[i + 1]] = i + 1;
    foran(j, 'a', 'z' + 1)
        if (j != s1[i + 1]) next[i][j] = next[i + 1][j];
  }
  
  int len = s1.length() / 2;
  forn(i, len)
    foran(j, 'a', 'z' + 1)
        if (next[i][j] >= len) next[i][j] -= len;
  
  cout << solve() << endl;
  
  return 0;
}