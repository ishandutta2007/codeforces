#include <iostream>

using namespace std;

int n;
string s;
int c[128];
int z;

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i += 2) {
        c[s[i]-'a']++;
        if (c[s[i+1]-'A']) {
            c[s[i+1]-'A']--;
        } else {
            z++;
        }
    }
    cout << z << "\n";
}