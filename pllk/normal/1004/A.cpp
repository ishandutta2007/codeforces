#include <iostream>
#include <set>

using namespace std;

int n, d;
int x[111];
set<int> s;

void check(int u) {
    int h = d;
    for (int i = 1; i <= n; i++) {
        h = min(h,abs(x[i]-u));
    }
    if (h == d) s.insert(u);
}

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        check(x[i]-d);
        check(x[i]+d);
    }
    cout << s.size() << "\n";
}