#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair <int, int> pii;
const int N=105;

int n, prvi;
pii p[N];
int sol[N];
int ima_prije[N], bio[N];
vector <vector <int> > v;
vector <int> komp;

void dfs(int node) {
    if (bio[node] || node==0) return;
    bio[node]=1;
    komp.push_back(node);
    dfs(p[node].second);
}

void load() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d %d", &p[i].first, &p[i].second);
        ima_prije[p[i].second]++;
    }
}

void solve() {
    for (int i=1; i<=n; ++i) {
        if (bio[i]) continue;
        if (p[i].first!=0) continue;
        //printf("Starting dfs from: %d\n", i);
        komp.clear();
        dfs(i);
        //komp.insert(komp.begin(), 0);
        //komp.push_back(0);
        v.push_back(komp);
    }
    /*for (int i=0; i<v.size(); ++i) {
        printf("Komp:\n");
        for (int j=0; j<v[i].size(); ++j) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }*/
    for (int i=0; i<v.size(); ++i) {
        //printf("Komp:\n");
        for (int j=0; j<v[i].size(); ++j) {
            //printf("node: %d, ", v[i][j]);
            if (j==v[i].size()-1) {
                if (i==v.size()-1) p[v[i][j]].second=0;
                else p[v[i][j]].second=v[i+1][0];
            }
            else {
                p[v[i][j]].second=v[i][j+1];
            }
            if (j==0) {
                if (i==0) p[v[i][j]].first=0;
                else p[v[i][j]].first=v[i-1][v[i-1].size()-1];
            }
            else {
                p[v[i][j]].first=v[i][j-1];
            }
            //printf("prije: %d, poslije %d\n", p[v[i][j]].first, p[v[i][j]].second);
        }
    }
    for (int i=1; i<=n; ++i) {
        printf("%d %d\n", p[i].first, p[i].second);
    }
}

int main() {
    load();
    solve();
}