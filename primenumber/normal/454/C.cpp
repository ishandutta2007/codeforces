#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

long double calc(int m, int n, int k) {
  return 1-pow((long double)k/m, n);
}

int main()
{
  int m,n;
  cin>>m>>n;
  long double ex = 0.0;
  FOR(i,1,m+1) ex += (calc(m,n,i-1) - calc(m,n,i)) * i;
  cout << setprecision(10) << fixed << ex << endl;
  return 0;
}