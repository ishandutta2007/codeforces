#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool prime[100100];

void solve(){
    int d;
    scanf("%d", &d);
    int ans1=1, ans2=1;
    for (int i=d+1;i<=100100;i++){
        if (i==100100) ans1 /= 0;
        if (prime[i]){
            ans1=i; break;
        }
    }
    for (int i=ans1+d;i<=100100;i++){
        if (i==100100) ans2 /= 0;
        if (prime[i]){
            ans2=i; break;
        }
    }
    ll ans=(ll)ans1*ans2;
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    fill(prime, prime+100100, 1);
    prime[0]=0, prime[1]=1;
    for(int i=2;i<100100;i++){
        if (!prime[i]) continue;
        for (int j=2;i*j<100100;j++) prime[i*j]=0;
    }
    while(t--){
        solve();
    }
    return 0;
}