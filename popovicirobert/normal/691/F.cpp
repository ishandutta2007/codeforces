#include <bits/stdc++.h>
#define MAXN 1000000
#define MAXVAL 3000000

using namespace std;

int a[MAXN + 1];
int cnt[MAXVAL + 1];
long long sp[MAXVAL + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, m, p;
    //ios::sync_with_stdio(false);
    //cin >> n;
    scanf("%d " ,&n);
    for(i = 1; i <= n; i++) {
        scanf("%d " ,&a[i]);
        cnt[a[i]]++;
    }
    for(i = 1; i <= MAXVAL; ++i)
      if(cnt[i] > 0)
         for(j = 1; j * i <= MAXVAL; ++j)
            if(i == j)
               sp[i * j] += 1LL * cnt[i] * (cnt[i] - 1);
            else
               sp[i * j] += 1LL * cnt[i] * cnt[j];
    for(i = 1; i <= MAXVAL; ++i)
        sp[i] += sp[i - 1];
    scanf("%d " ,&m);
    for(i = 1; i <= m; ++i) {
        scanf("%d " ,&p);
        printf("%I64d\n" ,1LL * n * (n - 1) - sp[p - 1]);
    }
    //cin.close();
    //cout.close();
    return 0;
}