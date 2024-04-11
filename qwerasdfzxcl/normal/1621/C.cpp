#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int ans[10010];

int query(int x){
    printf("? %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);

    fill(ans, ans+n+1, 0);
    for (int i=1;i<=n;i++) if (!ans[i]){
        while(query(i)!=i);
        int prv = i;
        while(true){
            int cur = query(i);
            ans[prv] = cur;
            prv = cur;
            if (cur==i) break;
        }
    }

    printf("! ");
    for (int i=1;i<=n;i++) printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}