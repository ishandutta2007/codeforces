#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int n;
    long double p;
    scanf("%d %Lf", &n, &p);
    int b = round(p*10000), a = 10000;
    //printf("%d %d\n", a, b);

    ll S = (ll)n * (n-1) * (n-2) / 3;
    for (int i=0;i<=n;i++){
        ll tmp = (ll)(n-i) * (n-i-1) * (n-i-2) / 3 + (ll) i * (n-i) * (n-i-1) / 2;
        if ((S-tmp) * a >= S * b){
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}