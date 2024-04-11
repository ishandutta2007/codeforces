#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[400400], b[400400], inv[400400];
const int MOD = 1e9+7;
bool visited[400400];

ll pw(int a, int e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    for (int i=1;i<=n;i++) scanf("%d", b+i);
    for (int i=1;i<=n;i++){
        inv[a[i]] = i;
    }
    fill(visited+1, visited+n+1, 0);
    int cnt = 0;
    for (int i=1;i<=n;i++) if (!visited[i]){
        int s = b[i], e = a[i];
        cnt++;
        visited[i] = 1;
        while(s!=e){
            int tmp = inv[s];
            s = b[tmp];
            visited[tmp] = 1;
        }
    }
    printf("%lld\n", pw(2, cnt));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}