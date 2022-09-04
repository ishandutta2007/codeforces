#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int n, m, q[maxn];

int a[maxn];
void dfs(int i, int prev){
    if (q[i] != 0)
        return;
    if (a[i] == 0)
        if (i == 0)
            q[i] = 2;
        else
        if (prev == i - 1)
            q[i] = 1;
        else
            dfs(i - 1, i), q[i] = q[i - 1];
    else
        if (i == n - 1)
            q[i] = 2;
        else
        if (prev == i + 1)
            q[i] = 1;
        else
            dfs(i + 1, i), q[i] = q[i + 1];
}


int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gallo.in");
    //ofstream cout("gallo.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c == '>')
            a[i] = 1;
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
        dfs(i, -1), answer += (q[i] == 2);
    cout << answer;
}