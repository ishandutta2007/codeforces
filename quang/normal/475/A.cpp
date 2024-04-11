#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n;
string s[5];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    cout << "+------------------------+\n";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    int cur = 1, vt = 1;
    for(int i = 1; i <= n; i++) {
        if(vt == 3 && cur != 1) vt++;
        s[vt][cur] = 'O';
        if(vt == 4) {
            vt = 1;
            cur += 2;
        } else vt++;
    }
    for(int i = 1; i <= 4; i++) cout << s[i] << endl;
    cout << "+------------------------+\n";
    return 0;
}