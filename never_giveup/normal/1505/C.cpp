#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << "YES\n";
        return 0;
    }
    int x = s[0] - 'A', y = s[1] - 'A';
    for (int i = 2; i < s.size(); i++) {
        int z = s[i] - 'A';
        if (z != (x + y) % 26) {
            cout << "NO\n";
            return 0;
        }
        x = y;
        y = z;
    }
    cout << "YES\n";
}