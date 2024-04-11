#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 10000010

using namespace std;

long long prime[N];
int n, m;
int sl[N];

int main() {
    //fi, fo;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        sl[x]++;
    }
    prime[1] = -1;
    for(int i = 2; i < N; i++)
    if(!prime[i]) {
        prime[i] = sl[i];
        for(int j = i + i; j < N; j += i)
        prime[i] += sl[j], prime[j] = -1;
    }
    for(int i = 1; i < N; i++){
        if(prime[i] == -1) prime[i] = 0;
        prime[i] += prime[i - 1];
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(l > N) l = N - 1;
        if(r > N) r = N - 1;
        cout << prime[r] - prime[l - 1] << endl;
    }
    return 0;
}