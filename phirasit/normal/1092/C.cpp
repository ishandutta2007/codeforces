#include <bits/stdc++.h>

using namespace std;

bool check(vector<string>& data, string s) {

    set<string> prefix, suffix;

    for (int i = 1; i < s.length(); ++i) {
        prefix.insert(s.substr(0, i));
        suffix.insert(s.substr(i, s.length() - i));
    }

    string out = "";
    for (string& str : data) {
        if (prefix.count(str)) {
            prefix.erase(str);
            out += "P";
        } else if (suffix.count(str)) {
            suffix.erase(str);
            out += "S";
        } else {
            return false;
        }
    }

    cout << out << endl;

    return true;

}
int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    string a, b;

    vector<string> data(2*n-2);
    for (string& s : data) {
        cin >> s;
        if (s.length() == n-1) {
            b = a;
            a = s;
        }
    }

    if (!check(data, a + b.back())) {
        check(data, b + a.back());
    }

    return 0;
}