#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool prime[10001000];
int cur[10001000], ans2[10001000];
ll ans[10001000];

ll pw(int a, int e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    ret = ret*ret;
    if (e&1) ret *= a;
    return ret;
}

void solve(){
    int x;
    scanf("%d", &x);
    printf("%d\n", ans2[x]);
}

int main(){
    for (int i=2;i<10001000;i++){
        cur[i] = i; ans[i] = 1; prime[i] = 1; ans2[i]=-1;
    }
    int i;
    for (i=2;i*i<10001000;i++){
        if (!prime[i]) continue;
        ans[i] = i+1;
        cur[i] = 1;
        for (int j=2;i*j<10001000;j++){
            prime[i*j]=0;
            int e = 1;
            while(!(cur[i*j]%i)){
                cur[i*j] /= i;
                e++;
            }
            ans[i*j] *= (pw(i, e)-1)/(i-1);
            //if (i*j==358011) printf("%lld\n", ans[i*j]);
        }
    }
    for (;i<10001000;i++) if (cur[i]!=1){
        ans[i] *= (pw(cur[i], 2)-1)/(cur[i]-1);
    }
    ans2[1]=1;
    for (int i=2;i<10001000;i++) if (ans[i]<10001000 && ans2[ans[i]]==-1){
        ans2[ans[i]]=i;
    }
    //printf("%lld\n", ans[358011]);
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}