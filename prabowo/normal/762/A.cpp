#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    
    vector<long long> v;
    for (long long i=1; i*i<=n; i++) {
        if (n % i == 0) {
            v.push_back(i); 
            if (i*i != n) v.push_back(n/i); 
        }
    }
    
    sort(v.begin(), v.end());
    
    if (v.size() < k) return 0 * printf("-1\n");
    printf("%lld\n", v[k-1]);
    
    return 0;
}