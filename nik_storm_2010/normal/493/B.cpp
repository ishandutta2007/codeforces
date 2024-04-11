#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;
typedef long long ll;

void finish(char s[]) {
    puts(s);
    exit(0);
}

int main() {
    int n, x;
    scanf("%d", &n);
    vector <ll> a, b;
    a.push_back(0), b.push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > 0) a.push_back(a[a.size() - 1] + x); else b.push_back(b[b.size() - 1] - x);
    }
    if (a[a.size() - 1] > b[b.size() - 1]) finish("first");
    if (a[a.size() - 1] < b[b.size() - 1]) finish("second");
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] > b[i]) finish("first");
        if (a[i] < b[i]) finish("second");
    }
    if (a.size() > b.size()) finish("first");
    if (a.size() < b.size()) finish("second");
    if (x > 0) finish("first"); else finish("second");
    return 0;
}