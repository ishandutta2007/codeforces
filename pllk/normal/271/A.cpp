#include <iostream>
#include <sstream>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = n+1; ; i++) {
        stringstream ss;
        ss << i;
        string s = ss.str();
        if (s[0] == s[1]) continue;
        if (s[0] == s[2]) continue;
        if (s[0] == s[3]) continue;
        if (s[1] == s[2]) continue;
        if (s[1] == s[3]) continue;
        if (s[2] == s[3]) continue;
        cout << i << endl;
        break;
    }
}