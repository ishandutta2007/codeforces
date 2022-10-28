#include "bits/stdc++.h"
using namespace std;
int n;
string str;
map < string , int > mp;
int main(){
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    cin >> n;
    int ans = 0;
    while(n--){
        cin >> str;
        ans += mp[str];
    }
    cout << ans;
}