#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> t[202020];
vector<int> u;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t[x].push_back(i);
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (t[c].size() > 0) {
            u.push_back(t[c].back());
            t[c].pop_back();
            c++;
        } else {
            bool ok = false;
            while (c > 0) {
                c -= 3;
                if (t[c].size() > 0) {
                    u.push_back(t[c].back());
                    t[c].pop_back();
                    c++;
                    ok = true;
                    break;
                }
            }
            if (!ok) break;
        }
    }
    if (u.size() == n) {
        cout << "Possible\n";
        for (int i = 0; i < n; i++) cout << u[i] << " ";
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }
}