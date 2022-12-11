#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

vector<int> T[N];
int l[N];
int d[N];
bool wi[N];

vector<int> V[N];
int low[N];
int need[N];


int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    queue<int> que;
    for(int i = 1; i <= n; i ++ ){
        cin >> l[i];
        d[i] = (int)1e9;
        if(l[i]) {
            d[i] = 0;
            que.push(i);
        }
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    int node;
    while(!que.empty()){
        node = que.front();
        que.pop();
        for(auto x : T[node]){
            if(d[x] > d[node] + 1){
                d[x] = d[node] + 1;
                que.push(x);
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(auto x : T[i]){
            if(d[i] == d[x]){
                wi[i] = true;
            }
        }
        if(wi[i]){
            V[d[i]].push_back(i);
        }
        low[i] = d[i];
    }
    for(int i = 0; i <= n; i ++ ){
        if(V[i].empty()) continue;
        for(int j = 1; j <= n; j ++ ){
            need[j] = (int)1e9;
        }
        deque<int> cur;
        for(auto x : V[i]){
            need[x] = 0;
            cur.push_back(x);
        }
        while(!cur.empty()){
            node = cur.front();
            cur.pop_front();
            for(auto x : T[node]){
                if(d[x] == d[node]){
                    if(need[x] > max(1, need[node] + 1)){
                        cur.push_back(x);
                        need[x] = max(1, need[node] + 1);
                    }
                }
                else if(d[node] + 1 == d[x]){
                    if(need[x] > need[node] - 1){
                        cur.push_front(x);
                        need[x] = need[node] - 1;
                    }
                }
            }
        }
        for(int j = 1; j <= n; j ++ ){
            if(need[j] <= 0){
                low[j] = min(low[j], i);
            }
        }

    }
    for(int i = 1; i <= n; i ++ ){
        cout << 2 * d[i] - low[i] << " ";

    }
    return 0;
}