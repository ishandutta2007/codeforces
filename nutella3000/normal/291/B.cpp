#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
string s;
bool check(int i) {
    if (s[i] != '"') return false;
    if (i == 0 || i == s.size() - 1 || s[i - 1] == ' ' || s[i + 1] == ' ') return true;
    return false;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    std::getline( std::cin,s);
    bool u = false;
    bool y = false;
    for(int i = 0;i < s.size();i++) {
        if (check(i)) {
            if (u) cout << ">" << '\n';
            else cout << "<";
            u = !u;
            continue;
        }
        if (u) {
            cout << s[i];
            continue;
        }
        if (y && s[i] == ' ') {
            y = false;
            cout << ">" << '\n';
            continue;
        }
        if (!y && s[i] != ' ') {
            y = true;
            cout << "<";
        }
        if (y) {
            cout << s[i];
        }
    }
    if (y) cout << ">";
}