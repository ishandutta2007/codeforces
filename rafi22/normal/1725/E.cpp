#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod = 998'244'353;

struct sparse_table {
    vector<vector<int>>values;
    int height;
    
    sparse_table() {}
    sparse_table(vector<int>a) {
        int n = a.size();
        values.emplace_back(a);
        height = 0;
        while((1 << height) < (int)values[height].size()) {
            values.emplace_back();
            for(int i = 0; i + (1 << height) < (int)values[height].size(); i++) {
                int l = values[height][i];
                int r = values[height][i + (1 << height)];
                values.back().emplace_back(min(l, r));
            }
            height++;
        }
    }
    int get_min(int l, int r) {
        int len = r - l + 1;
        int bit = 31 - __builtin_clz(len);
        return min(values[bit][l], values[bit][r - (1 << bit) + 1]);
    }
};

const int MAX_N = 200'001;

int pre_order[MAX_N], pre_order_inv[MAX_N], depth[MAX_N], t = 0;
vector<int>adj[MAX_N], where[MAX_N];
vector<pair<int, int>>my_adj[MAX_N];
bool marked[MAX_N];

long long answer = 0;

struct lca {
    sparse_table s;
    
    vector<int>traversal, first_app;
    
    lca(int n) {
        first_app.resize(n);
        dfs(0, -1);
        s = sparse_table(traversal);
    }
    
    void dfs(int x, int p) {
        first_app[pre_order[x]] = traversal.size();
        traversal.push_back(pre_order[x]);
        for(int y : adj[x]) {
            if(y != p) {
                dfs(y, x);
                traversal.push_back(pre_order[x]);
            }
        }
    }
    
    int get(int a, int b) {
        int p = s.get_min(first_app[pre_order[a]], first_app[pre_order[b]]);
        return pre_order_inv[p];
    }
};

void dfs_pre(int x, int p) {
    pre_order[x] = t++;
    pre_order_inv[pre_order[x]] = x;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            dfs_pre(y, x);
        }
    }
}

int dfs_calc(int x, int p, int total) {
    int result = marked[x];
    for(auto [y, d] : my_adj[x]) {
        if(y != p) {
            long long a = dfs_calc(y, x, total);
            
            long long b = total - a;
            
            long long first = (a * (a - 1) / 2) % mod;
            first = (first * b) % mod;
            
            long long second = (b * (b - 1) / 2) % mod;
            second = (second * a) % mod;
            
            answer = (answer + (first + second) * d) % mod;
            
            result += a;
        }
    }
    
    return result;
}

const int MAX_A = 200'001;

int main() {
    
    int n; scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        where[x].push_back(i);
    }
    
    for(int i = 0; i < n - 1; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs_pre(0, -1);
    
    lca my_lca = lca(n);
    
    vector<bool>prime(MAX_A, true);
    
    vector<int>parent(n, -1);
    vector<bool>in(n, false);
    
    for(int i = 2; i < MAX_A; i++) {
        if(prime[i]) {
            vector<int>my_nodes;
            for(int j = i; j < MAX_A; j += i) {
                prime[j] = false;
                for(int x : where[j]) {
                    in[x] = true;
                    marked[x] = true;
                    my_nodes.push_back(pre_order[x]);
                }
            }
            
            if(!my_nodes.empty()) {
                sort(my_nodes.begin(), my_nodes.end());
                vector<int>my_tree;
                int current = pre_order_inv[my_nodes[0]];
                
                my_tree.push_back(current);
                for(int i = 1; i < (int)my_nodes.size(); i++) {
                    int x = pre_order_inv[my_nodes[i]];
                   
                    int l = my_lca.get(current, x);
                    
                    if(l == current) {
                        parent[x] = current;
                    } else {
                        if(in[l]) {
                            parent[x] = l;
                        } else {
                            
                            my_tree.push_back(l);
                            in[l] = true;
                            
                            while(parent[current] != -1 && depth[parent[current]] > depth[l])
                                current = parent[current];
                            
                            
                            if(parent[current] == -1) {
                                parent[current] = l;
                                parent[l] = -1;
                                parent[x] = l;
                            } else {
                                int p = parent[current];
                                parent[current] = l;
                                parent[l] = p;
                                parent[x] = l;
                            }
                        }
                    }
                    
                    current = x;
                    my_tree.push_back(x);
                }
                
                
                for(int x : my_tree) {
                    if(parent[x] != -1) {
                        int d = abs(depth[x] - depth[parent[x]]);
                        my_adj[x].emplace_back(parent[x], d);
                        my_adj[parent[x]].emplace_back(x, d);
                    }
                }
                
                dfs_calc(my_tree[0], -1, my_nodes.size());
                
                for(int x : my_tree) {
                    my_adj[x].clear();
                    in[x] = false;
                    marked[x] = false;
                    parent[x] = -1;
                }
            }
        }
    }
    
    printf("%lld\n", answer);
}