#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int cnt[200200];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    for (int i=0;i<m;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if (x>y) swap(x, y);
        if (!cnt[x]) ans++;
        cnt[x]++;
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int op;
        scanf("%d", &op);
        if (op==1){
            int x, y;
            scanf("%d %d", &x, &y);
            if (x>y) swap(x, y);
            if (!cnt[x]) ans++;
            cnt[x]++;
        }
        else if (op==2){
            int x, y;
            scanf("%d %d", &x, &y);
            if (x>y) swap(x, y);
            cnt[x]--;
            if (!cnt[x]) ans--;
        }
        else printf("%d\n", n-ans);
    }

    ///init
    fill(cnt, cnt+n+1, 0);
}

int main(){
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}