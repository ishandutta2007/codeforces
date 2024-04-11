#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<string> p;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "pwd") {
            cout << '/';
            for (int j = 0; j < p.size(); j++) {
                cout << p[j] << '/';
            }
            cout << endl;
        } else {
            cin >> s;
            int a = 0;
            if (s[0] == '/') {
                p.clear();
                a = 1;
            }
            for (int j = a; j < s.length(); j++) {
                if (j == s.length()-1 || s[j+1] == '/') {
                    string u = s.substr(a, j-a+1);
                    if (u == "..") p.pop_back();
                    else p.push_back(u);
                    a = j+2;
                }
            }
        }
    }
}