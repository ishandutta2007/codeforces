#include<cstdio>
#include<set>
#include<map>

using namespace std;
const int N = 2e5;

int a[N];
set <int> one;
map <int, int> last;

void add(int x) {
    if (last[x] != 0) { last[x]++; return; }
    set <int>::iterator it = one.find(x);
    if (it == one.end()) { one.insert(x); return; }
    one.erase(it);
    last[x] = 1;
}

void del(int x) {
    set <int>::iterator it = one.find(x);
    if (it != one.end()) { one.erase(it); return; }
    last[x]--;
    if (last[x] == 0) one.insert(x);
}

void compute() {
    if (one.size() == 0) { printf("Nothing\n"); return; }
    set <int>::iterator it = one.end();
    it--;
    printf("%d\n", *it);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= k; i++) add(a[i]);
    compute();
    for (int i = k + 1; i <= n; i++) {
        add(a[i]);
        del(a[i - k]);
        compute();
    }
    return 0;
}