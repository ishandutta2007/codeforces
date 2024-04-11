#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)2e5 + 9;
set<int>adj[N];
set<int>not_visited;

int cnt[N];

int n;
void dfs(int cur,int ix){
    cnt[ix]++;
    not_visited.erase(cur);
    auto x = not_visited.begin();
    int current;
    while(x!=not_visited.end()){
        current=*x;
        if(!adj[cur].count(current) and not_visited.count(current))
            dfs(current,ix);
        x=not_visited.upper_bound(current);
    }
}

int main(){
    fastIO;
    int m;
    cin >> n >> m;
    int l,r;
    for(int i = 1;i<=n;i++)not_visited.insert(i);
    while(m--){
        cin >> l >> r;
        adj[l].insert(r);
        adj[r].insert(l);
    }
    int p = 0;
    for(int j = 1;j<=n;j++){
        if(!not_visited.count(j))continue;
        dfs(j,p++);
    }
    cout << p << "\n";
    sort(cnt,cnt+p);
    for(int i = 0;i<p;i++)cout << cnt[i] << " ";
    return 0;
}