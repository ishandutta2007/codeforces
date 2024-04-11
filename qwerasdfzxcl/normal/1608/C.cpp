#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int ans[100100], orga[100100], orgb[100100];
pair<int, int> a[100100], b[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d", &a[i].first);
        a[i].second = i;

        orga[i] = a[i].first;
    }
    for (int i=1;i<=n;i++){
        scanf("%d", &b[i].first);
        b[i].second = i;

        orgb[i] = b[i].first;
    }

    sort(a+1, a+n+1); sort(b+1, b+n+1);

    int x = orga[b[n].second], y = orgb[a[n].second];

    int prva = n, prvb = n;
    while(true){
        int posa = lower_bound(a+1, a+n+1, make_pair(x, -1)) - a;
        int posb = lower_bound(b+1, b+n+1, make_pair(y, -1)) - b;

        //printf("%d %d %d %d\n", posa, prva, posb, prvb);

        if (posa==prva && posb==prvb) break;

        for (int i=posa;i<prva;i++){
            if (y > orgb[a[i].second]){
                y = orgb[a[i].second];
            }
        }

        for (int i=posb;i<prvb;i++){
            if (x > orga[b[i].second]){
                x = orga[b[i].second];
            }
        }

        prva = posa, prvb = posb;
    }

    fill(ans+1, ans+n+1, 0);

    for (int i=prva;i<=n;i++) ans[a[i].second] = 1;
    for (int i=prvb;i<=n;i++) ans[b[i].second] = 1;

    for (int i=1;i<=n;i++) printf("%d", ans[i]);
    printf("\n");

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}