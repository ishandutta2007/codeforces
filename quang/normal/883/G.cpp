#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second


using namespace std;

int const N = 3e5 + 5;

int n, m, S;
int ans[N], ok[N], cnt = 0, type[N];

vector < pair < pair < int, int >,  pair < int, int > > > a[N];


void Printf(){
    for(int i=1; i<=m; i++){
        if(type[i] == 1)    continue;
        if(ans[i] == 1){
            cout << '+';
        }
        else
            cout << '-';
    }
    cout << endl;
}

void dfs_max(int u){
    ok[u] = 1;
    cnt++;
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i].f.f;
        int t = a[u][i].f.s;
        int id = a[u][i].s.f;
        int sign = a[u][i].s.s;
        if(ok[v] == 0){
            ans[id] = sign;
            dfs_max(v);
        }
    }
}

void Out(int u){
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i].f.f;
        int t = a[u][i].f.s;
        int id = a[u][i].s.f;
        int sign = a[u][i].s.s;
        ans[id] = -sign;
    }
}

void dfs_min(int u){
    ok[u] = 1;
    cnt++;
    Out(u);
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i].f.f;
        int t = a[u][i].f.s;
        int id = a[u][i].s.f;
        int sign = a[u][i].s.s;
        if(t == 2)  continue;
        if(ok[v] == 0){
            ans[id] = sign;
            dfs_min(v);
        }
    }

}

main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m >> S;
    int t, u, v;
    for(int i=1; i<=m; i++){
        cin >> type[i] >> u >> v;
        if(type[i] == 2){
            a[u].push_back(mp(mp(v, type[i]), mp(i, 1)));
            a[v].push_back(mp(mp(u, type[i]), mp(i, -1)));
        }
        else{
            a[u].push_back(mp(mp(v, type[i]), mp(i, 1)));
        }
    }

    memset(ok, 0, sizeof(ok));
    memset(ans, -1, sizeof(ans));
    dfs_max(S);
    cout << cnt << endl;
    Printf();



    cnt = 0;
    memset(ok, 0, sizeof(ok));
    memset(ans, -1, sizeof(ans));
    dfs_min(S);
    cout << cnt << endl;
    Printf();



}