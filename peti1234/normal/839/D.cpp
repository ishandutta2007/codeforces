#include <bits/stdc++.h>

using namespace std;
int n;
long long k;
int cnt[1000001];
long long h[200001];
long long e[1000001];
int mod = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    h[0] = 1;
    for (int i =1; i <= 200000; i++) {
        h[i] = h[i - 1] * 2;
        h[i] %= mod;
    }
    for (int i =2; i <= 1000000; i++) {
        for (int j = 2*i; j <= 1000000; j += i) {
            cnt[i] += cnt[j];
        }
    }
    for (int i = 1000000; i > 1; i--) {
        e[i]= (cnt[i] * h[cnt[i] - 1])%mod;
        for (int j = 2 * i; j <= 1000000; j += i) {            
            e[i] -= e[j]%mod-mod;
            e[i] %= mod;
        }
        k += e[i]*i;
        k %= mod;
    }
    cout << k << endl;
}