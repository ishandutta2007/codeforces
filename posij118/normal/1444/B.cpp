#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

long long po(long long a, int x){
    if(x == 1) return a;

    else if(x % 2 == 0){
        long long xx = po(a, x / 2);
        return (xx*xx) % M;
    }
    else return (a*po(a, x - 1)) % M;
}

int main(){
    int n;
    cin >> n;

    int a[2*n];
    for(int i = 0; i<2*n; i++){
        cin >> a[i];
    }

    sort(a, a + 2*n);

    long long sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    for(int i = 0; i<n; i++){
        sum1 += a[i];
        sum2 += a[i + n];
    }

    long long ans = sum2 - sum1;
    long long den = 1;

    for(int i = 1; i<=2*n; i++){
        ans *= i;
        ans %= M;
    }

    for(int i = 1; i<=n; i++){
        den *= i;
        den %= M;
        den *= i;
        den %= M;
    }

    cout << (ans*po(den, M - 2)) % M;


}