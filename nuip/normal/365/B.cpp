#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    if(a.size() >= 2) {
        int maxi = 2;
        int cnt = 0;
        for(int i=0; i+2<n; i++) {
            if(a[i]+a[i+1] != a[i+2]) {
                maxi = max(maxi, cnt+2);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        maxi = max(maxi, cnt+2);
        cout << maxi << endl;
    }else {
        cout << 1 << endl;
    }
    return 0;
}