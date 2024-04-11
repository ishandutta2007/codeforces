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
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
 
using namespace std;

string a[100500];
bool b[100500];
int n;
bool ok = 1;

int go(int pos)
{
   
   if (pos >= n) ok = 0;
   if (!ok) return -1;
   if (!b[pos]) return pos;
   int i = go(pos + 1);
   if (!ok) return -1;
   int j = go(i + 1);
   if (!ok) return -1;
   a[pos] += '<';
   a[i] += ',';
   a[j] += '>';
   return j;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n",&n);
  char c;
  int i = 0;
  string s = "";
  while (1)
  {
	c = getchar();
	if (c == '\n') break;
	if (c == ' ') 
	{ 
		if (s == "pair") b[i] = 1; else b[i] = 0;
        i++; s.clear(); continue;		
	}
	s += c;
  }
  
  if (s == "pair") b[i] = 1; else b[i] = 0;
  n = i + 1;
  
  if (n == 1)
  {
	if (b[0]) puts("Error occurred"); else puts("int");
	return 0;
  }
  
  go(0);
  
  if (!ok  || a[n - 1].empty()) { puts("Error occurred"); return 0; }
  
  
  printf("pair<");
  foran(i, 1, n)
	if (b[i]) 
	{
		printf("pair");
		printf("%s",a[i].c_str());
	}
	 else
	{
		printf("int");
		printf("%s",a[i].c_str());
	}
  return 0;
}