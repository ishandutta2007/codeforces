#include <bits/stdc++.h>
 
using namespace std;
 
int n,
    arr[300001];
map<int, int> cnt[2];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    
    long long tot = 0, px = 0;
    cnt[1][0]++;
    for (int i = 0; i < n; i++) {
        px ^= arr[i];
        tot += cnt[(i % 2) ^ 0][px];
        cnt[i % 2][px]++;
    }
    
    cout << tot << '\n';
}