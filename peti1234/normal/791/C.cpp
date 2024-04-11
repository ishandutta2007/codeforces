#include <bits/stdc++.h>

using namespace std;
vector <string> p{"A", "B", "C", "D", "E", "F", "Aa", "Ba", "Ca", "Da", "Ea", "Fa","Ab", "Bb", "Cb", "Db", "Eb", "Fb","Ac", "Bc", "Cc", "Dc", "Ec", "Fc","Ad", "Bd", "Cd", "Dd", "Ed", "Fd","Ae", "Be", "Ce", "De", "Ee", "Fe","Af", "Bf", "Cf", "Df", "Ef", "Ff", "Ag", "Bg", "Cg", "Dg", "Eg", "Fg","Ah", "Bh", "Ch", "Dh", "Eh", "Fh"};
int n, k, id;
string t[51];
bool h[51];
int main()
{
    cin >> n >> k;
    for (int i=k; i<=n; i++) {
        string x;
        cin >> x;
        if (x=="NO") {
            h[i]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!h[i]) {
            t[i]=p[id];
            id++;
        } else {
            t[i]=t[i-k+1];
        }
    }
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    return 0;
}