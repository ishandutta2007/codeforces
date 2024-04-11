#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int cnt[20];
    fill(cnt, cnt + 20, 0);

    for(int i = 0; i<n; i++){
        cin >> a[i];
        for(int j = 0; j<20; j++){
            if(a[i] & (1 << j)) cnt[j]++;
        }
    }

    long long b[n];
    fill(b, b + n, 0);
    long long ans = 0;
    for(int j = 0; j<20; j++){
        for(int i = 0; i<cnt[j]; i++){
            b[i] += (1 << j);
        }
    }

    for(int i = 0; i<n; i++){
        ans += b[i] * b[i];
    }

    cout << ans;

}