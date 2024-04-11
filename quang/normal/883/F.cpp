#include <bits/stdc++.h>

using namespace std;

string normalize(string s) {
    while (true) {
        int pos = s.find("u");
        if (pos == string::npos) break;
        s = s.substr(0, pos) + "oo" + s.substr(pos + 1);
    }
    while (true) {
        int pos = s.find("kh");
        if (pos == string::npos) break;
        s = s.substr(0, pos) + "h" + s.substr(pos + 2);
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    set<string> S;
    while (n--) {
        string s;
        cin >> s;
        string t = normalize(s);
        //cerr << s << ' ' << t << endl;
        S.insert(t);
    }
    cout << S.size() << endl;
}