#include <iostream>

using namespace std;

string x = "Bulbasaur";
string s;
int c[256];
int z;

int main() {
    cin >> s;
    for (auto u : s) c[u]++;
    while (true) {
        int ok = 1;
        for (auto u : x) {
            if (c[u]) {
                c[u]--;
            } else ok = 0;
        }
        if (!ok) break;
        z++;
    }
    cout << z << "\n";
}