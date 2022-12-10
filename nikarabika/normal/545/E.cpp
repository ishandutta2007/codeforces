#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<int, int> pie;
typedef pair<LL, LL> ple;

const int maxn = 3e5 + 10;
vector<pie> v[maxn];
LL d[maxn];
LL E[maxn];
set<ple> s;
int par[maxn];
int n, m, st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int fi, se, w;
        cin >> fi >> se >> w;
        v[fi].PB(MP(se, i));
        v[se].PB(MP(fi, i));
        E[i] = w;
    }
    cin >> st;
    memset(d, 127, sizeof d);
    d[st] = 0;
    par[st] = -1;
    s.insert(MP(st, 0));
    while(s.size()){
        int x = s.begin()->L;
        s.erase(s.begin());
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i].L,
                w = E[v[x][i].R],
                e = v[x][i].R;
            if(d[x] + w < d[y]){
                par[y] = e;
                s.erase(MP(y, d[y]));
                d[y] = d[x] + w;
                s.insert(MP(y, d[y]));
            }
            else if(d[x] + w == d[y] and E[par[y]] > w){
                par[y] = e;
            }
        }
    }
    vector<int> ans;
    LL sum = 0;
    for(int i = 1; i <= n; i++)
        if(par[i] != -1)
            sum += E[par[i]], ans.PB(par[i]);
    sort(ans.begin(), ans.end());
    cout << sum << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}