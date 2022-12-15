#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#define mod 1000000007
using namespace std;

long long n,k,val,cur;

int main() {
    scanf("%lld %lld", &n, &k);
    cur = 1;
    while (n--) {
        scanf("%lld", &val);
        cur = __gcd(k, cur * val / __gcd(cur, val));
    }
    if (k == cur) printf("YES");
    else printf("NO");
}