#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;


string str;
string aux;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int m, i, l, r, k;
    ios::sync_with_stdio(false);
    cin >> str;
    aux = str;
    cin >> m;
    while(m > 0) {
        m--;
        cin >> l >> r >> k;
        l--;
        r--;
        k %= (r - l + 1);
        int pos = l + k;
        for(i = l; i <= r; i++) {
            if(pos > r)
               pos = l;
            aux[pos] = str[i];
            pos++;
        }
        for(i = l; i <= r; i++)
            str[i] = aux[i];
    }
    cout << str;
    //cin.close();
    //cout.close();
    return 0;
}