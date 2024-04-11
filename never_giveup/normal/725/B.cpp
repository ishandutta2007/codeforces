#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

ll n;

char c;

ll a;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gallo.in");
    //ofstream cout("gallo.out");
    #endif
    ios::sync_with_stdio(0);
    while (1){
        cin >> c;
        if (c >= '0' && c <= '9')
            n = n * 10 + c - '0';
        else
            break;
    }
    if (c == 'f')
        a = 1;
    else
    if (c == 'e')
        a = 2;
    else
    if (c == 'd')
        a = 3;
    else
    if (c == 'a')
        a = 4;
    else
    if (c == 'b')
        a = 5;
    else
        a = 6;
    if (n % 2 == 1)
        cout << ((n - 1) / 4) * 16 + a;
    else
        cout << ((n - 1) / 4) * 16 + 7 + a;
}