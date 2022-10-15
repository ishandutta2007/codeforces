#include <iostream>

using namespace std;

string s1, s2;
int n;

int lol[256][100];
int ok[256][100];

int main() {
    cin >> s1 >> s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, x;
        char p, k;
        cin >> m >> p >> x >> k;
        if (k == 'y') lol[p][x]++;
        else lol[p][x] += 2;
        if (ok[p][x]) continue;
        if (lol[p][x] < 2) continue;
        ok[p][x] = 1;
        if (p == 'h') cout << s1 << " ";
        else cout << s2 << " ";
        cout << x << " " << m << "\n";
    }
}