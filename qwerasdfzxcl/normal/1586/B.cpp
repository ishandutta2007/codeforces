#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int chk[100100];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    fill(chk+1, chk+n+1, 0);
    for (int i=0;i<m;i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        chk[y] = 1;
    }
    int idx = -1;
    for (int i=1;i<=n;i++) if (!chk[i]) {idx = i; break;}
    for (int i=1;i<=n;i++) if (idx!=i) printf("%d %d\n", idx, i);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}