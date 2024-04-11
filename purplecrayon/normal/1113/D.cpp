#include <bits/stdc++.h>
using namespace std;
 
int solveOdd(const string& s) {
    return 2;
}
 
int solveEven(const string& s) {
    if (s.length() % 2 == 1) {
        return 2;
    }
    string lf = s.substr(0, s.length() / 2);
    string rg = s.substr(s.length() / 2, s.length() / 2);
    if (lf != rg) return 1;
    return solveEven(lf);
}
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
 
    string s;
    cin >> s;
    if (s.length() < 3) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> cnt(255);
    for(char c : s) {
        ++cnt[c];
    }
    if (*max_element(cnt.begin(), cnt.end()) >= s.length() - 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << (s.length() % 2 == 0 ? solveEven(s) : solveOdd(s)) << endl;
 
    return 0;
}