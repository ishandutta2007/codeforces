#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void normalise(string &s) {
    for (auto &i : s) {
        if (i >= 'A' && i <= 'Z') i += 'a' - 'A';
        if (i == 'i') i = '1';
        if (i == 'o') i = '0';
        if (i == 'l') i = '1';
    }
}
 
int main() {
    string inp;
    cin >> inp;
    normalise(inp);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        normalise(t);
        if (t == inp) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}