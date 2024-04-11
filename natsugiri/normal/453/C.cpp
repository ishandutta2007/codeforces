#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

typedef vector<int> Ary;
typedef vector<Ary> Mat;

int N, M;
Mat G, T;
int X[100011];
int use[100011];
vector<int> ans;

inline void push(int i) {
    ans.push_back(i);
    X[i] = 1 - X[i];
}

int dfs_tree(int v, int num) {
    int ret = X[v];
    use[v] = num;

    for (int i=0; i<(int)G[v].size(); i++) {
        if (use[G[v][i]] == -1) {
            int tmp = dfs_tree(G[v][i], num);
            if (tmp) {
                T[v].push_back(G[v][i]);
                ret += tmp;
            }
        }
    }            
    return ret;       
}

void rec(int v) {
    push(v);
    for (int i=0; i<(int)T[v].size(); i++) {
        rec(T[v][i]);
        push(v);
    }
    for (int i=0; i<(int)T[v].size(); i++) {
        if (X[T[v][i]]) {
            push(T[v][i]);
            push(v);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    G = Mat(N);
    T = Mat(N);
    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=0; i<N; i++) scanf("%d", X+i);
    
    memset(use, -1, sizeof use);

    int root = -1;
    int ma = 0, cnt = 0;
    for (int i=0; i<N; i++) cnt += X[i];

    for (int i=0; i<N; i++) {
        if (use[i] == -1) {
            int tmp = dfs_tree(i, i);
            if (tmp == cnt) root = i;
            ma = max(ma, tmp);
        }
    }

    if (ma != cnt) { // not connected
        puts("-1");
        return 0;
    }

    if (root != -1) {
        rec(root);
        if (X[root] == 1) ans.pop_back();
    }

    printf("%d\n", (int)ans.size());
    for (int i=0; i<(int)ans.size(); i++) {
        printf("%d%c", ans[i]+1, i+1==(int)ans.size() ? '\n' : ' ');
    }

    return 0;
}