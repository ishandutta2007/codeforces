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

int gcd(int a,int b) { return (b==0)?a:gcd(b,a%b); }
int lcm(int a,int b) { return a * b / gcd(a,b); }

int n;
char a[1010];
char b[1010];
int A,B;
int res[3];

int win(char x,char y)
{
    if (x == y) return 2;
    if (x == 'R')
        return 1?y == 'S':0;
    if (x == 'S')
        return 1?y == 'P':0;
    return 1?y == 'R':0;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  scanf("\n");
  gets(a);
  gets(b);
  A = (int)strlen(a); B = (int)strlen(b);
  int len = lcm(A,B);
  res[0] = res[1] = res[2] = 0;
  
  int L = n % len;
  int ans[2]; ans[0] = ans[1] = 0;
  
  forn(i,len)
  {
   res[win(a[i%A],b[i%B])]++;
   if (i == L - 1) ans[0] = res[0], ans[1] = res[1]; 
  }
  
  forn(i,2) res[i] = (n / len) * res[i];
  cout << res[0] + ans[0] << " " << res[1] + ans[1] << endl;
  return 0;
}