#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<ll> fib;
int a[111], cnt[111], ok[111], mx;

void zeck(int x){
    for (int i=(int)fib.size()-1;i>=1;i--) if (fib[i] <= x){
        x -= fib[i];
        cnt[i]++;
        mx = max(mx, i);

        if (!x) ok[i] = 1;
    }

    assert(!x);
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    for (int i=1;i<=100;i++) cnt[i] = 0;
    for (int i=1;i<=100;i++) ok[i] = 0;
    mx = 0;
    for (int i=1;i<=n;i++) zeck(a[i]);

    if (mx==1 && cnt[1]==1) {printf("YES\n"); return;}

    if (cnt[1]==1){
        bool flag = 0;
        for (int i=3;i<=mx;i+=2) if (cnt[i]==2 && ok[i]){
            flag = 1;
            cnt[i]--;
            cnt[1]++;
            for (int k=2;k<i;k+=2) cnt[k]++;

            break;
        }

        if (!flag && mx%2==1 && cnt[mx]==1 && cnt[2]==0 && ok[mx]){
            for (int k=2;k<mx;k+=2) cnt[k]++;
            cnt[mx]--;
            mx--;
            cnt[1]++;
        }
    }

    if (cnt[1] != 2) {printf("NO\n"); return;}
    for (int i=2;i<=mx;i++) if (cnt[i]!=1) {printf("NO\n"); return;}

    printf("YES\n");
}

int main(){
    fib.resize(2);
    fib[0] = fib[1] = 1;
    for (int i=2;i<=100;i++){
        fib.push_back(fib[i-1] + fib[i-2]);
        if (fib[i] >= 1e18) break;
    }

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}