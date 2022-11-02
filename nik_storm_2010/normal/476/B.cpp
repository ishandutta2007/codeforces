#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string s1, s2;
int need, good, all;

void rec(int x, int pos) {
    if (x == s2.length()) {
        all++;
        if (pos == need) good++;
        return;
    }
    if (s2[x] == '+') rec(x + 1, pos + 1);
    if (s2[x] == '-') rec(x + 1, pos - 1);
    if (s2[x] == '?') rec(x + 1, pos + 1), rec(x + 1, pos - 1);
}

int main() {
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.length(); i++) need += (s1[i] == '+' ? +1 : -1);
    rec(0, 0);
    cout << setprecision(9) << fixed << (double)good / all << endl;
    return 0;
}