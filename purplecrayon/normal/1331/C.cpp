#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s=bitset<6>(n).to_string();
    string t=s;
    vector<int> p{0, 5, 3, 2, 4, 1};
    for (int i = 0; i < 6; i++) t[i] = s[p[i]];
    cout << bitset<6>(t).to_ulong() << '\n';
}