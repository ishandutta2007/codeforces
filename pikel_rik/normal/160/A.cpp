#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a (n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int c = 0;
    int sum = 0, sum1 = accumulate(a.begin(), a.end(), 0);
    for (int i = n-1; i >= 0; i--) {
        sum += a[i];
        c += 1;
        if (sum > sum1 - sum)
            break;
    }
    cout << c;
}