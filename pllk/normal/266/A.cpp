#include <iostream>

using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    int t = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i-1] == s[i]) t++;
    }
    cout << t << endl;
}