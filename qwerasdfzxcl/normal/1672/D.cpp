#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[200200], cnt[200200];

void solve(){
    int n;
    scanf("%d", &n);
    fill(cnt+1, cnt+n+1, 0);
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
    }
    for (int i=1;i<=n;i++){
        scanf("%d", b+i);
    }

    int prv = -1, pt = n;
    for (int i=n;i;i--){
        if (b[i]==prv){
            cnt[b[i]]++;
            continue;
        }

        while(pt && a[pt]!=b[i]){
            if (cnt[a[pt]]==0){printf("NO\n"); return;}
            cnt[a[pt]]--;
            pt--;
        }
        if (pt==0) {printf("NO\n"); return;}
        pt--;
        prv = b[i];
    }
    printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}