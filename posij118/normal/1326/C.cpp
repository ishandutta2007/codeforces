#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

int main(){
    long long n, k;
    cin >> n >> k;

    int p[n];
    int pos[k];
    int ctr = 0;
    long long ans = 1;

    for(int i = 0; i<n; i++){
        cin >> p[i];
        if(p[i] > n - k){
            pos[ctr] = i;
            ctr++;
        }
    }

    sort(pos, pos + k);
    for(int i = 0; i<k - 1; i++){
        ans *= (pos[i + 1] - pos[i]);
        ans %= M;
    }

    cout << ((2*n - k + 1) * k) / 2 << " " << ans << endl;

}