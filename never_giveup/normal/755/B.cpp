/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 2e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int n, m;

int a, b, c;

set<string> q;

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        q.insert(s);
        a++;
    }
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        if (q.count(s))
            a--, c++;
        else
            b++;
    }
    int x = c % 2;
    if (x == 0)
        if (a > b)
            cout << "YES";
        else
            cout << "NO";
    else
        if (a >= b)
            cout << "YES";
        else
            cout << "NO";
}