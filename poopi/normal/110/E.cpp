                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#pragma comment(linker, "/STACK:50000000")
using namespace std;

#define int64 long long
#define P pair<int, bool>


int n;
int64 tot[100010];
int64 luk[100010];
int64 res;
vector <P> adj[100001];

bool isluk(int x){
    while(x){
        int d = x % 10;
        if(d != 4 && d != 7)
            return false;
        x /= 10;
    }
    return true;
}

void dfs1(int v, int par){
    tot[v] = 1;
    luk[v] = 0;
    for(int i = 0; i < adj[v].size(); i++){
        int j = adj[v][i].first;
        if(j == par)
            continue;
        dfs1(j, v);
        tot[v] += tot[j];
        luk[v] += (adj[v][i].second ? tot[j] : luk[j]);
    }   
}

void dfs2(int v, int par, int64 up){
    res += 2 * luk[v] * up + luk[v] * (luk[v] - 1) + up * (up - 1);
    for(int i = 0; i < adj[v].size(); i++){
        int j = adj[v][i].first;
        if(j == par)
            continue;
        int64 nup;
        if(adj[v][i].second)
            nup = n - tot[j];
        else nup = up + luk[v] - luk[j];
        dfs2(j, v, nup);
    }
}

int main(){
    while(cin >> n){
        res = 0;
        int a, b, c;
        for(int i = 0; i < n - 1; i++){
            cin >> a >> b >> c;
            bool fl = isluk(c);
            a--, b--;
            adj[a].push_back(P(b, fl));
            adj[b].push_back(P(a, fl));
        }
        dfs1(0, -1);
        dfs2(0, -1, 0);
        cout << res << endl;
    }
    return 0;
}