#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int numZ = 0, numN = 0;
    for (char u : s) {
        numZ += (u == 'z');
        numN += (u == 'n');
    }
    for (int i = 1; i <= numN; i++) cout << 1 << ' ';
    for (int i = 1; i <= numZ; i++) cout << 0 << ' ';
        cout << endl;
    return 0;
}