#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

string str1, str2;
string sol, aux, aux1;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str1 >> str2;
    int n = str1.size();
    sol = str1 + str2;
    for(i = 0; i < n; i++) {
        aux.push_back(str1[i]);
        aux1 = aux + str2[0];
        if(aux1 < sol)
            sol = aux1;
    }
    cout << sol;
    //cin.close();
    //cout.close();
    return 0;
}