#include <iostream>
#include <vector>

using namespace std;

int n;
int a[2020][2020];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<int> v1;
    int m1[2020] = {0};
    v1.push_back(0);
    m1[0] = 1;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (m1[j]) continue;
            if (a[v1[i]][j]) {
                v1.push_back(j);
                m1[j] = 1;
            }
        }
    }
    if (v1.size() < n) {
        cout << "NO\n";
        return 0;
    }

    vector<int> v2;
    int m2[2020] = {0};
    v2.push_back(0);
    m2[0] = 1;
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (m2[j]) continue;
            if (a[j][v2[i]]) {
                v2.push_back(j);
                m2[j] = 1;
            }
        }
    }
    if (v2.size() < n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}