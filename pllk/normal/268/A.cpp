#include <iostream>

using namespace std;

int n;
int v[50][2];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[i][0] == v[j][1]) t++;
        }
    }
    cout << t << endl;
}