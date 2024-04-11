#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

int a[MAXN + 1];

int lvl[MAXN + 1];

void dfs(int nod) {
    for(auto it : g[nod])
       if(lvl[it] == 0) {
           lvl[it] = lvl[nod] + 1;
           dfs(it);
       }
}

int sol[MAXN + 1];

vector <int> divi;
int fr[MAXN + 1];

void dfs1(int nod) {
    for(auto it : divi) {
        if(a[nod] % it == 0)
            fr[it]++;
    }
    for(auto it : g[nod])
            if(lvl[it] > lvl[nod])
                dfs1(it);
    for(auto it : divi) {
        if(lvl[nod] - 1 <= fr[it])
            sol[nod] = max(sol[nod], it);
        if(a[nod] % it == 0)
            fr[it]--;
    }
}

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


void dfs2(int nod, int val) {
    val = gcd(val, a[nod]);
    sol[nod] = max(sol[nod], val);
    for(auto it : g[nod])
        if(lvl[nod] < lvl[it])
             dfs2(it, val);
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lvl[1] = 1;
    dfs(1);
    for(int d = 1; d * d <= a[1]; d++) {
        if(a[1] % d == 0) {
             divi.push_back(d);
             divi.push_back(a[1] / d);
             if(a[1] == d * d)
                divi.pop_back();
        }
    }
    dfs1(1);
    a[1] = 0;
    dfs2(1, 0);
    for(i = 1; i <= n; i++)
        cout << sol[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}