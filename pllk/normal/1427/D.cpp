#include <iostream>
#include <vector>

using namespace std;

int n;
int p[100];
vector<vector<int>> v;

void move(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2) {
    vector<int> m;
    if (a1 <= a2) {
        m.push_back(a2-a1+1);
    }
    m.push_back(b2-b1+1);
    m.push_back(c2-c1+1);
    if (d1 <= d2) m.push_back(d2-d1+1);
    v.push_back(m);
    vector<int> u;
    for (int i = d1; i <= d2; i++) u.push_back(p[i]);
    for (int i = c1; i <= c2; i++) u.push_back(p[i]);
    for (int i = b1; i <= b2; i++) u.push_back(p[i]);
    for (int i = a1; i <= a2; i++) u.push_back(p[i]);
    for (int i = 1; i <= n; i++) p[i] = u[i-1];
    /*for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";*/
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    while (true) {
        bool f = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (p[i]+1 == p[j]) {
                    int c = 0;
                    for (int k = i-1; k >= j; k--) {
                        if (p[k]+1 == p[k+1]) c++;
                        else break;
                    }
                    move(1,j-1,j,i-c-1,i-c,i,i+1,n);
                    f = true;
                    goto skip;
                }
            }
        }
        skip:
        if (!f) break;
    }
    cout << v.size() << "\n";
    for (auto x : v) {
        cout << x.size() << " ";
        for (auto y : x) cout << y << " ";
        cout << "\n";
    }
}