#include <bits/stdc++.h>

using namespace std;
int n;
long long mego;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        string x;
        cin >> x;
        if (x=="Icosahedron") {
            mego+=20;
        }
        if (x=="Cube") {
            mego+=6;
        }
        if (x=="Tetrahedron") {
            mego+=4;
        }
        if (x=="Octahedron") {
            mego+=8;
        }
        if (x=="Dodecahedron") {
            mego+=12;
        }
    }
    cout << mego << endl;
    return 0;
}