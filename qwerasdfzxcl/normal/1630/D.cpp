#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll INF = 1e18;
int a[1001000];
ll V[1001000], C[1001000], S[2];

ll myabs(ll x){
    if (x<0) return -x;
    return x;
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++) scanf("%d", a+i);

    int G = 0;
    for (int i=1;i<=m;i++){
        int x;
        scanf("%d", &x);
        if (!G) G = x;
        else G = __gcd(G, x);
    }

    fill(V, V+n+1, INF);
    fill(C, C+n+1, 0);
    S[0] = S[1] = 0;

    for (int i=1;i<=n;i++){
        V[i%G] = min(V[i%G], myabs(a[i]));
        if (a[i]<0) C[i%G]++;
    }

    for (int i=0;i<G;i++) S[C[i]%2] += V[i] * 2;

    ll tmp = 0;
    for (int i=1;i<=n;i++) tmp += myabs(a[i]);

    printf("%lld\n", tmp - min(S[0], S[1]));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}