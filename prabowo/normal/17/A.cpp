#include <bits/stdc++.h>
using namespace std;

int n, k;
bool prime[1002];
vector <int> prima;

int main () {
    scanf("%d %d", &n, &k);
    for (int i=2; i<=n; i++) prime[i] = 1;
    for (int i=2; i<=n; i++) if (prime[i]) {
        prima.push_back(i);
        for (int j=2*i; j<=n; j+=i) prime[j] = 0;
    }

    int cnt = 0;
    for (int i=1; i<prima.size(); i++) cnt += (prima[i] + prima[i-1] + 1 <= n && prime[prima[i] + prima[i-1] + 1]);
    if (cnt < k) puts("NO");
    else puts("YES");
    return 0;
}