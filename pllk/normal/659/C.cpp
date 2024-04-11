#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int n, m;
unordered_set<int> z;
vector<int> u;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        z.insert(a);
    }
    int c = 0;
    for (int i = 1; ; i++) {
        if (z.count(i)) continue;
        if (i > m) break;
        m -= i;
        u.push_back(i);
        c++;
    }
    cout << c << "\n";
    for (int i = 0; i < u.size(); i++) cout << u[i] << " ";
    cout << "\n";
}