#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c = 0;
    cin >> n;
    
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Tetrahedron")
            c += 4;
        else if (s == "Cube")
            c += 6;
        else if (s == "Octahedron")
            c += 8;
        else if (s == "Dodecahedron")
            c += 12;
        else if (s == "Icosahedron")
            c += 20;
    }
    cout << c;
}