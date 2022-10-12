#include <bits/stdc++.h>
using namespace std;

int n, k;
pair <int, int> x[300000];

int main() {
    scanf ("%d", &n);
    for (int i=0; i<n; i++) scanf ("%d", &x[i].first), x[i].second = i; 
    sort(x, x + n);
    scanf ("%d", &k);
    
    long long ans = 0;
    long long sum = 0;
    long long mini;
    int idx = 0;
    for (int i=0; i<k; i++) {
        ans += 1LL * x[i].first * i - sum;
        sum += x[i].first;
    }
    
    mini = ans;
    
    for (int i=k; i<n; i++) {
        sum -= x[i-k].first;
        ans -= (sum - 1LL * x[i-k].first * (k-1));
        ans += 1LL * x[i].first * (k-1) - sum;
        sum += x[i].first;
        
        if (ans < mini) {
            idx = i - k + 1;
            mini = ans;
        }
    }

    // cout << mini << endl;
    // cout << idx << endl;
    
    for (int i=0; i<k; i++) printf ("%d ", x[idx + i].second + 1);
    
    
    
    
    return 0;
}