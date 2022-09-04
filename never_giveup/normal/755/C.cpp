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

int n;

int p[maxn];

int dsu_get(int x){
    return p[x] == x ? x : p[x] = dsu_get(p[x]);
}

bool dsu_unite(int a, int b){
    int x = dsu_get(a), y = dsu_get(b);
    if (x == y)
        return 0;
    if (rand() % 2)
        p[x] = y;
    else
        p[y] = x;
    return 1;
}

int answer;

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    answer = n;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        x--;
        if (dsu_unite(i, x))
            answer--;
    }
    cout << answer;
}