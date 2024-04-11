#include <iostream>
#include <vector>

using namespace std;

int n, k;
string s;
vector<char> u;

int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            u.push_back('(');
        } else {
            if (k < n && u.size() > 0 && u.back() == '(') {
                u.pop_back();
                k += 2;
            } else {
                u.push_back(')');
            }
        }
    }
    for (auto x : u ) cout << x;
    cout << "\n";
}