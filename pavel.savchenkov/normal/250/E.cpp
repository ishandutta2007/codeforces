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
#define all(A) ((A).begin(), (A).end())
#define sz(A) ((int)(A).size())
#define y1 fucking_y1

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

int n, m;
char S[110][(int)1e4 + 10];

void run_away() {
    puts("Never");
    exit(0);
}

int main() {
  scanf("%d%d\n", &n, &m);

  for (int i = 0; i < n; i++, scanf("\n")) {
        S[i][0] = S[i][m + 1] = '#';
    for (int j = 1; j <= m; j++)
        scanf("%c", &S[i][j]);
  }


  LL res = 0; int j = 1; bool dir = true;

  for (int i = 0; i < n - 1; i++) {
    int L = j; int R = j;

    while (1) {
    if  (dir) {
        while (S[i][R] == '.' && !(S[i][R] == '.' && S[i + 1][R] == '.')) R++;

        if  (S[i + 1][R] == '.' && S[i][R] == '.') {
            res += 1LL * (R - j); ++res;
            j = R;
            break;
        }

        R--;
        if  (S[i][R + 1] == '#') {
            res += 1LL * (R - j); ++res;
            dir = false;
            j = R;
        } else {
            res += 1LL * (R - j); ++res;
            dir = false;
            j = R;
            S[i][R + 1] = '.';
        }
    } else {
        while (S[i][L] == '.' && !(S[i + 1][L] == '.' && S[i][L] == '.')) L--;

        if  (S[i + 1][L] == '.' && S[i][L] == '.') {
            res += 1LL * (j - L); ++res;
            j = L;
            break;          
        } 

        L++;

        if  (S[i][L - 1] == '#') {
            res += 1LL * (j - L); ++res;
            dir = true;
            j = L;
        } else {
            res += 1LL * (j - L); ++res;
            dir = true;
            j = L;
            S[i][L - 1] = '.';
        }
      }

        if  (S[i][L - 1] == '#' && S[i][R + 1] == '#') run_away();
    }                             
  }

  cout << res << '\n';
  return 0;
}