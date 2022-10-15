#include <iostream>

using namespace std;

int n;
string s;

int main() {
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int t = 0;
        int p = (int)s.length();
        if (p >= 5) {
            string a = s.substr(0, 5);
            string b = s.substr(p-5, 5);
            if (a == "miao." && b == "lala.") t = 0;
            else if (a == "miao.") t = 2;
            else if (b == "lala.") t = 1;
        }
        if (t == 0) cout << "OMG>.< I don't know!\n";
        if (t == 1) cout << "Freda's\n";
        if (t == 2) cout << "Rainbow's\n";
    }
}