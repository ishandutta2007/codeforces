#include <cstdio>

using namespace std;

int cnt[10];

bool good(int n)
{
 cnt[4] = cnt[7] = 0;
 int len = 0;
 while (n > 0)
 {
  len++;
  if (n % 10 != 7 && n % 10 != 4) return 0;
  cnt[n % 10]++;
  n /= 10;
 }
 return cnt[4] == len / 2 && cnt[7] == len / 2 && len % 2 == 0;
}

int main() {
 int n;
 scanf("%d",&n);
 if (n > 77774444) { puts("4444477777"); return 0; }
 for (int i = n; ; i++)
  if (good(i)) { printf("%d",i); return 0; }
 return 0;
}