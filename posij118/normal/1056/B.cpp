#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    long long ans = 0;
    cin >> n >> m;

    long long cnt[m];
    fill(cnt, cnt + m, 0);

    for(int i = 0; i<m; i++){
        if(i >= n) break;
        cnt[(i*i) % m] += ((n - i - 1) / m + 1);
    }

    cnt[0]--;
    cnt[(n*n) % m]++;

    for(int i = 0; i<m; i++){
        ans += (cnt[i] * cnt[(m - i) % m]);
    }

    cout << ans;

}