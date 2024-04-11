#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <numeric>
#include <map>
#include <math.h>
#define MAX 500002
#define inf (1LL << 62)
#define se second
#define fi first
#define pb push_back
#define m1 998244353
#define epi 1e-15d
#define NO "IMPOSSIBLE"
#define Ans(i, n) cout << "Case #" << i << ": " << n << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int>> graph(MAX);
int Size[MAX];

void dfs(int start){
    set<int> visited;
    vector<int> stack{start};
    while(stack.size()){
        int visit = stack.back();
        stack.pop_back();
        if(Size[visit]){
            continue;
        }
        Size[visit] = 1;
        visited.insert(visit);
        vector<int> linked = graph[visit];
        for(auto i:linked){
            if(visited.find(i) == visited.end()){
                stack.pb(i);
            }
        }
    }
    int cnt = visited.size();
    for(auto i:visited){
        Size[i] = cnt;
    }
}

int main(){
    fill(Size, Size+MAX, 0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        int prev;
        if(k){
            cin >> prev;
        }
        for(int j=1;j<k;j++){
            int cur;
            cin >> cur;
            graph[cur].pb(prev);
            graph[prev].pb(cur);
            prev = cur;
        }
    }
    for(int i=1; i<=n;i++){
        if(Size[i] == 0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout << Size[i] << ' ';
    }
    return 0;
}