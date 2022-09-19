#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;

std::vector<int> a;
std::map<int, long long> m1;
std::map<int, long long> m2;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) {
            res += m2[a[i] / k];
            m2[a[i]] += m1[a[i] / k];
        }
        m1[a[i]]++;
    }
    printf("%I64d\n", res);
    return 0;
}