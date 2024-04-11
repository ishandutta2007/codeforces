#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pp;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
const int max_n = int(2e5) + 10;

ll pd[max_n];

vector<pp> edge[max_n];
int n;

int a[max_n];
int par[max_n];
int sz[max_n];

typedef multiset<ll> M;

int ans[max_n];

void pre_dfs(int x){
    for(auto E : edge[x]){
        int y, d; tie(y, d) = E;
        pd[y] = pd[x] + d;
        pre_dfs(y);
        sz[x] += sz[y];
    }
    sz[x]++;
}

M dfs(int x){
    M cur;
    int big_child = -1;
    for(auto E : edge[x]){
        int y=E.first;
        if(big_child == -1 || sz[big_child] < sz[y]) big_child = y;
    }
    if(big_child == -1){
        cur.insert(pd[x] - a[x]);
        return cur;
    }
    cur = dfs(big_child);
    for(auto E : edge[x]){
        int y, d; tie(y, d) = E;
        if(y == big_child) continue;
        auto tmp = dfs(y);
        cur.insert(tmp.begin(), tmp.end());
    }
    while(cur.size()){
        auto it = cur.upper_bound(pd[x]);
        if(it == cur.end()) break;
        cur.erase(it);
    }
    ans[x] = cur.size();
    cur.insert(pd[x] - a[x]);
    return cur;
}

int main()
{
    read(n);
    for(int i=1; i<=n; ++i) read(a[i]);
    for(int i=2; i<=n; ++i){
        int a, b; read(a, b);
        par[i]=a; edge[a].pb({i, b});
    }
    pre_dfs(1);
    dfs(1);
    for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
    return 0;
}