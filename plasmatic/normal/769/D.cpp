#include <bits/stdc++.h>
 
using namespace std;
 
int n, k,
    arr[100001];
long long cnt[10001];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        cnt[arr[i]]++;
    }
    
    long long tot = 0;
    
    for (int i = 0; i <= 10000; i++) {
        for (int j = i; j <= 10000; j++) {
            if (i == j && !k) {
                tot += (cnt[j] * (cnt[j] - 1)) / 2;
            }
            else if (__builtin_popcount(i ^ j) == k)
                tot += cnt[i] * cnt[j];
        }
    }
            
    
    cout << tot << '\n';
}