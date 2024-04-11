#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int m;
    scanf("%d", &m);
    
    int p; char s[10];
    vector<int> v1, v2;
    
    while (m--) {
        scanf("%d %s", &p, s);
        if (s[0] == 'P') v2.push_back(p);
        else v1.push_back(p);
    }
    
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    
    int cnt = 0; long long sum = 0;
    while (v1.size() > 0 && a > 0) {
        a--; sum += v1.back(); v1.pop_back();
        cnt++;
    }
    
    while (v2.size() > 0 && b > 0) {
        b--; sum += v2.back(); v2.pop_back();
        cnt++;
    }
    
    while ((v1.size() > 0 || v2.size() > 0) && c > 0) {
        c--; cnt++;
        if (v1.size() && v2.size()) {
            if (v1.back() < v2.back()) {
                sum += v1.back();
                v1.pop_back();
            } else {
                sum += v2.back();
                v2.pop_back();
            }
        } else if (v1.size()) {
            sum += v1.back();
            v1.pop_back();
        } else {
            sum += v2.back();
            v2.pop_back();
        }
    }
    
    printf("%d %lld\n", cnt, sum);
    
    return 0;
}