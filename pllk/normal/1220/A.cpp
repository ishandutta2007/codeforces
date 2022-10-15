#include <iostream>

using namespace std;

int n;
string s;
int z[128];

int main() {
    cin >> n;
    cin >> s;
    for (auto c : s) z[c]++;
    while (z['n']) {
        z['o']--;
        z['n']--;
        z['e']--;
        cout << "1 ";
    }
    while (z['z']) {
        z['z']--;
        z['e']--;
        z['r']--;
        z['o']--;
        cout << "0 ";
    }
    cout << "\n";
}