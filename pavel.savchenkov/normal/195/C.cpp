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
#include <assert.h>

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
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int n;
string a[100500];
int id[100500];
int sz = 0;
string T;
int ID = -1;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  char c = ' ';
  while (1)
  {
      c = getchar();
      if  (c == '\n') break;
  }

  T.clear();

  forn(i, n)
  {

    c = ' '; string s = ""; bool was = 0;
    while (1)
    {
        c = getchar();
        if  (c == '\n') break;
        if  (c == '"' && !was) was = 1; else
         if  (c == '"' && was) was = 0;
        if  (c != ' ' || was) s += c;
    }

    if  (s.empty()) continue;

    if  (s == "try")
     a[sz] = s, id[sz] = i, sz++;

    if  (s[0] == 't' && s[1] == 'h')
     for (int j = 6; j < s.length() - 1; j++)
      T += s[j], ID = i;

    if  (s[0] == 'c')
    {
        string type = ""; string text = "";
        int j = 6;

        for (; s[j] != ','; j++)
         type += s[j];

        for (j += 2; j < s.length() - 2; j++)
         text += s[j];

        if  (ID != -1 && a[sz - 1] == "try" && id[sz - 1] < ID && type == T)
        {
            cout << text << "\n"; return 0;
        }
        sz--;
    }

  }

  cout << "Unhandled Exception";
  return 0;
}