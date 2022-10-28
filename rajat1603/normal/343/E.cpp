#include "bits/stdc++.h"
using namespace std;
const int N = 2e2 + 2;
const int M = 2e3 + 3;
const int inf = 1e6 + 6;
int n , m;
int cur;
int A[M] , B[M] , C[M];
vector < int > v[N];
int a[M] , b[M] , c[M];
int flow[N][N];
int que[N];
int qs , qe;
int dist[N];
int pre[N];
bool allowed[N];
void addedge(int x , int y , int z){
    A[cur] = x;
    B[cur] = y;
    C[cur] = z;
    v[x].emplace_back(cur);
    ++cur;
    A[cur] = y;
    B[cur] = x;
    C[cur] = z;
    v[y].emplace_back(cur);
    ++cur;
}
bool bfs(int start , int finish){
    qs = 0;
    qe = 0;
    for(int i = 1 ; i <= n ; ++i){
        dist[i] = inf;
        pre[i] = -1;
    }
    dist[start] = 0;
    pre[start] = 0;
    que[qe++] = start;
    while(qs < qe){
        int node = que[qs++];
        for(int edge : v[node]){
            if(c[edge]){
                int next = b[edge];
                if(dist[next] > dist[node] + 1){
                    dist[next] = dist[node] + 1;
                    pre[next] = edge;
                    que[qe++] = next;
                }
            }
        }
    }
    return (dist[finish] < inf);
}
int getflow(int s , int t , vector < int > nodes){
    for(int i = 0 ; i < cur ; ++i){
        a[i] = A[i];
        b[i] = B[i];
        c[i] = C[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        allowed[i] = 0;
    }
    for(int node : nodes){
        allowed[node] = 1;
    }
    int res = 0;
    while(bfs(s , t)){
        int node = t;
        int val = inf;
        while(node != s){
            val = min(val , c[pre[node]]);
            node = a[pre[node]];
        }
        res += val;
        node = t;
        while(node != s){
            c[pre[node]] -= val;
            c[pre[node] ^ 1] += val;
            node = a[pre[node]];
        }
    }
    return res;
}
pair < int , vector < int > > solve(vector < int > nodes){
    if(nodes.size() == 1){
        return make_pair(0 , vector < int > {nodes.back()});
    }
    int mnval = inf;
    int x , y;
    for(int i = 0 ; i < nodes.size() ; ++i){
        for(int j = i + 1 ; j < nodes.size() ; ++j){
            int a = nodes[i];
            int b = nodes[j];
            if(flow[a][b] < mnval){
                mnval = flow[a][b];
                x = a;
                y = b;
            }
        }
    }
    vector < int > lft;
    vector < int > rgt;
    lft.clear();
    rgt.clear();
    for(int node : nodes){
        if(flow[x][node] == mnval){
            rgt.emplace_back(node);
        }
    }
    for(int node : nodes){
        if(flow[y][node] == mnval && flow[x][node] != mnval){
            lft.emplace_back(node);
        }
    }
    auto res1 = solve(lft);
    auto res2 = solve(rgt);
    vector < int > res;
    res.clear();
    for(int node : res1.second){
        res.emplace_back(node);
    }
    for(int node : res2.second){
        res.emplace_back(node);
    }
    return make_pair(res1.first + res2.first + mnval , res);
}
bool visited[N];
void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = 1;
    for(int edge : v[node]){
        if(c[edge]){
            int next = b[edge];
            dfs(next);
        }
    }
}
void findcut(int start){
    for(int i = 1 ; i <= n ; ++i){
        visited[i] = 0;
    }
    dfs(start);
}
void allpairsflow(vector < int > nodes){
    if(nodes.size() == 1){
        flow[nodes.back()][nodes.back()] = inf;
    }
    else{
        int x = nodes[0];
        int y = nodes[1];
        int f = getflow(x , y , nodes);
        flow[x][y] = flow[y][x] = f;
        vector < int > lft;
        vector < int > rgt;
        findcut(x);
        for(int i = 1 ; i <= n ; ++i){
            if(allowed[i]){
                if(visited[i]){
                    lft.emplace_back(i);
                }
                else{
                    rgt.emplace_back(i);
                }
            }
        }
        allpairsflow(lft);
        allpairsflow(rgt);
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    cur = 0;
    for(int i = 0 ; i < m ; ++i){
        int x , y , z;
        scanf("%d %d %d" , &x , &y , &z);
        addedge(x , y , z);
    }
    vector < int > nodes(n);
    for(int i = 0 ; i < n ; ++i){
        nodes[i] = i + 1;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            flow[i][j] = inf;
        }
    }
    allpairsflow(nodes);
    for(int k = 1 ; k <= n ; ++k){
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                if(i != j && max(flow[i][k] , flow[k][j]) < inf){
                    if(flow[i][j] == inf){
                        flow[i][j] = -1;
                    }
                    flow[i][j] = max(flow[i][j] , min(flow[i][k] , flow[k][j]));
                }
            }
        }
    }   
    /*for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            cout << flow[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1 ; i < n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            flow[i][j] = flow[j][i] = getflow(i , j , nodes);
        }
    }
    cout << endl;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            cout << flow[i][j] << " ";
        }
        cout << endl;
    }*/
    auto it = solve(nodes);
    printf("%d\n" , it.first);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , it.second[i - 1] , " \n"[i == n]);
    }
}