#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    long long ans = k;

    int b[n];
    vector<int> diff;
    for(int i = 0; i<n; i++){
        cin >> b[i];
        if(i != 0) diff.push_back(b[i] - b[i - 1]);
    }

    sort(diff.begin(), diff.end());
    for(int i = 0; i<n - k; i++){
        ans += diff[i];
    }

    cout << ans;

}