#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

string str, aux;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> str;
    aux = str;
    reverse(aux.begin(), aux.end());
    cout << str << aux;
    //cin.close();
    //cout.close();
    return 0;
}