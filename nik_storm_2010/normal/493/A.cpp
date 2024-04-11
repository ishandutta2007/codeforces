#include <iostream>

#include <fstream>

using namespace std;
const int N = 1e2;

int used[2][N];

int main() {
    ios_base::sync_with_stdio(false);
    string t[2];
    cin >> t[0] >> t[1];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m, num;
        string name, f;
        cin >> m >> name >> num >> f;
        int team = (name == "h" ? 0 : 1);
        if (used[team][num] >= 2) continue;
        used[team][num] += (f == "y" ? 1 : 2);
        if (used[team][num] >= 2) cout << t[team] << " " << num << " " << m << "\n";
    }
    return 0;
}