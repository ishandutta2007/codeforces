#include <iostream>

using namespace std;

string s;
int k;

int main() {
    cin >> s >> k;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 'a') s[i] += ('a'-'A');
        if (s[i] < 97 + k) s[i] -= ('a'-'A');
    }
    cout << s << endl;
}