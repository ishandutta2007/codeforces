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
#include <iomanip>
using namespace std;

#define int64 long long
#define P pair<int, double>

int n;
double ex;
vector <int> adj[100010];

void dfs(int idx, int par, int dep){
    ex += (double)1 / dep;
    for(int i = 0; i < adj[idx].size(); i++){
        int j = adj[idx][i];
        if(j == par) continue;
        dfs(j, idx, dep + 1);
    }
}

int main(){
    cin >> n;
    int a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << fixed << setprecision(10);
    dfs(0, -1, 1);
    cout << ex << endl;
    return 0;
}