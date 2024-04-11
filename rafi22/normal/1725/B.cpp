#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    long long d; scanf("%lld", &d);
    vector<long long>a(n);
    for(long long &x : a)
        scanf("%lld", &x);
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int result = 0;
    while(l <= r) {
        long long my_power = a[r];
        while(my_power <= d) {
            l++;
            my_power += a[r];
        }
        
        if(l <= r) {
            result++;
        }
        r--;
    }
    
    printf("%d\n", result);
    
}