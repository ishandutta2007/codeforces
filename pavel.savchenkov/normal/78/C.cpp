#include <cstdio>

using namespace std;
int n,m,k;

bool can()
{
 for (int i=2; i*i<=m; i++)
  if (m % i == 0 && m / i >= k) return 1;
 if (k == 1 && m != 1) return 1;
 return 0;
}

bool solve()
{
 if (!can()) return 0;
 if (n % 2 == 0) return 0;
 return 1;
}

int main() {
 scanf("%d%d%d",&n,&m,&k);
 puts(solve()?"Timur":"Marsel");
 return 0;
}