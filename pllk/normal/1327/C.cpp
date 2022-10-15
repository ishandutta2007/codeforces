#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s = "";
    for (int i = 1; i <= n-1; i++) s += "U";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m-1; j++) s += "L";
        for (int j = 1; j <= m-1; j++) s += "R";
        s += "D";
    }
    cout << s.size() << "\n";
    cout << s << "\n";
}