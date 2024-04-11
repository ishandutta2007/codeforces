#include <cstdio>
#include <vector>

using namespace std;

vector <int> t1, t2, t3;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) t1.push_back(i);
        if (t == 2) t2.push_back(i);
        if (t == 3) t3.push_back(i);
    }
    size_t sz = t1.size();
    sz = min(sz, t2.size());
    sz = min(sz, t3.size());
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) printf("%d %d %d\n", t1[i], t2[i], t3[i]);
    return 0;
}