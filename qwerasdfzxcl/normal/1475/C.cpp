#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a1[200200], a2[200200];

void solve(){
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    for (int i=0;i<k;i++) scanf("%d", a1+i);
    for (int i=0;i<k;i++) scanf("%d", a2+i);
    sort(a1, a1+k);
    sort(a2, a2+k);
    ll tmpa1=0, tmpa2=0, tmpb1=1, tmpb2=1;
    for (int i=1;i<k;i++){
        if (a1[i]!=a1[i-1]){
            tmpa1 += (tmpb1-1)*tmpb1/2;
            tmpb1=1;
        }
        else tmpb1++;
        if (a2[i]!=a2[i-1]){
            tmpa2 += (tmpb2-1)*tmpb2/2;
            tmpb2=1;
        }
        else tmpb2++;
    }
    tmpa1 += (tmpb1-1)*tmpb1/2;
    tmpa2 += (tmpb2-1)*tmpb2/2;
    ll ans=(ll)k*(k-1)/2;
    printf("%lld\n", ans-tmpa1-tmpa2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}