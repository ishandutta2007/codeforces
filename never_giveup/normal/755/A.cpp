/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int n;

bool q[maxn];

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 2; i < maxn; i++)
        if (!q[i])
            for (int j = 2 * i; j < maxn; j += i)
                q[j] = 1;
    for (int i = 1;; i++)
    if (q[n * i + 1]){
        cout << i;
        return 0;
    }
}