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

char a[200][200];
int n,m;
int k1[200]; 
int k2[200];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(k1,0,sizeof(k1));
  memset(k2,0,sizeof(k2));
  cin >> n >> m; scanf("\n");
  forn(i,n)
    gets(a[i]);
  
  forn(i,n)
    forn(j,m)
        if (a[i][j] == '*') k1[i]++, k2[j]++;
  
  int ii; int jj;
  
  forn(i,n)
    forn(j,m)
        if (a[i][j] == '*') 
        {
            if (k1[i] == 1) ii = i + 1;
            if (k2[j] == 1) jj = j + 1;
        }
  
  cout << ii << " " << jj << endl;
  return 0;
}