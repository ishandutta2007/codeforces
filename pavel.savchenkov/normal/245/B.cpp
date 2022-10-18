#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

char s[100];
int n;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  gets(s);
  n = (int)strlen(s);

  if  (s[0] == 'f' && s[1] == 't' && s[2] == 'p') {
    forn(i, 3)
        putchar(s[i]);
    printf("://");

    bool was1 = 0; bool was2 = 0;
    for (int i = 3; s[i]; i++) {
        if  (s[i] == 'r' && s[i + 1] == 'u' && !was1 && i != 3)
            putchar('.'), was1 = 1;
        putchar(s[i]);
        if  (i > 0 && i != n - 1 && s[i] == 'u' && s[i - 1] == 'r' && was1 && !was2)
            putchar('/'), was2 = 1;
    }
  } else {
    forn(i, 4)
        putchar(s[i]);
    printf("://");

    bool was1 = 0; bool was2 = 0;
    for (int i = 4; s[i]; i++) {
        if  (s[i] == 'r' && s[i + 1] == 'u' && !was1 && i != 4)
            putchar('.'), was1 = 1;
        putchar(s[i]);
        if  (i > 0 && i != n - 1 && s[i] == 'u' && s[i - 1] == 'r' && was1 && !was2)
            putchar('/'), was2 = 1;
  }
  }
  return 0;
}