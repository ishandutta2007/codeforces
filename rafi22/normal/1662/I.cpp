#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long S(vector<long long>&p, int a, int b) {
    if(a == 0)
        return p[b];
    return p[b] - p[a - 1];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<long long>p(n), x(m);
    for(long long &y : p)
        scanf("%lld", &y);
    for(long long &y : x) {
        scanf("%lld", &y);
        y *= 2;
    }
    sort(x.begin(), x.end());
    for(int i = 1; i < n; i++)
        p[i] += p[i - 1];
    
    long long answer = 0;
    for(long long hut = 0; hut < n; hut++) {
        long long hutPos = hut * 200;
        auto it = lower_bound(x.begin(), x.end(), hutPos);
        if(it == x.end()) {
            answer = max(answer, S(p, hut, n - 1));
        } else if(*it != hutPos) {
            if(it == x.begin()) {
                answer = max(answer, S(p, 0, hut));
            } else {
                long long right = *it; it--;
                long long left = *it;
                long long len = right - left; //it's even
                long long distToLeft = hutPos - left;
                long long shopPosition = min(right - 1, 2 * hutPos - left - 1);
                
                long long shopToRight = right - shopPosition; //it's odd
                
                long long furthestRight = shopPosition + shopToRight / 2;
                
                long long furthestHut = min((long long)n - 1, furthestRight / 200);
                
                answer = max(answer, S(p, hut, furthestHut));
                
            }
            
        }
    }
    
    printf("%lld\n", answer);
    
    return 0;
}