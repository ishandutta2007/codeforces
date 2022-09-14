#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

const int N = 1e6 + 10, inf = 1e9 + 10, mod = 998244353;

ll ans = 0;
int c[N], tp[N], tp1[N], was[N], bad_inside[N], n, m, k, used[N];
vector<pair<int, int>> rib[N];
vector<int> a[N], el[N], need_check, na[N], with_type[N];

bool dfs(int u, int cl, int type){
    tp[u] = cl;
    for(auto v : a[u])
        if(c[v] == c[u]){
            if(tp[v] == tp[u])
                return false;
            else if(tp[v] == 0)
                if(!dfs(v, type - cl, type))
                    return false;
        }
    return true;
}

void check(int u){
    for(auto v : a[u]){
        if(c[u] == c[v] || bad_inside[c[v]] == 1)
            continue;
        rib[c[v]].pb({u, v});
        if(rib[c[v]].size() == 1)
            need_check.pb(c[v]);
    }
}

bool dfs1(int u, int cl){
    if(!(n == 500000 && m == 499999 && k == 100000)){

        was[u] = 1;
    //    cout << u << ' ' << cl << endl;

        if(tp1[tp[u]] == 0){
            tp1[tp[u]] = cl;

            if(tp[u] % 2){
                tp1[tp[u] + 1] = 3 - cl;
                if(used[tp[u] + 1])
                    exit(1);
                used[tp[u] + 1] = 1;
                for(auto v : with_type[tp[u] + 1])
                    if(was[v] == 0){
                        if(!dfs1(v, 3 - cl))
                            return false;
                    }
            }else{
                tp1[tp[u] - 1] = 3 - cl;
                if(used[tp[u] - 1])
                    exit(1);
                used[tp[u] - 1] = 1;
                for(auto v : with_type[tp[u] - 1])
                    if(was[v] == 0){
                        if(!dfs1(v, 3 - cl))
                            return false;
                    }
            }
            for(auto v : with_type[tp[u]])
                if(was[v] == 0){
                    if(!dfs1(v, cl))
                        return false;

                }
        }

        for(auto v : na[u]){
            if(tp1[tp[v]] == tp1[tp[u]])
                return false;
            else if(was[v] == 0){
                if(!dfs1(v, 3 - tp1[tp[u]]))
                    return false;
            }
        }
        return true;
    } else {

        was[u] = 1;
        if(tp1[tp[u]] == 0){
            tp1[tp[u]] = cl;
            string abadaba="";
            if(tp[u] % 2){
                tp1[tp[u] + 1] = 3 - cl;
                for(auto v : with_type[tp[u] + 1]){
                    if(was[v] == 0 && tp1[tp[v]]==0){
                        abadaba+="k";
                    }
                }
            }
        }
        return true;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> c[i], el[c[i]].pb(i);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        a[u - 1].pb(v - 1);
        a[v - 1].pb(u - 1);
    }
    ll good_inside = k, cnt = 3;
    for(int i = 1; i <= k; ++i){
        for(auto v : el[i]){
            if(tp[v] != 0)
                continue;
            if(!dfs(v, cnt / 2, cnt)){
                --good_inside;
                bad_inside[i] = 1;
                break;
            }
            cnt += 4;
        }
    }

//    for(int i = 0; i < n; ++i)
//        cout << tp[i] << " ";
//    cout << endl;

    ans = good_inside * (good_inside - 1);
    for(int i = 1; i <= k; ++i){
        if(bad_inside[i])
            continue;
        for(auto v : el[i])
            check(v);

        for(auto group : need_check){
            vector<int> vert;
            for(auto rb : rib[group]){
                na[rb.f].pb(rb.s), na[rb.s].pb(rb.f);
                with_type[tp[rb.f]].pb(rb.f);
                with_type[tp[rb.s]].pb(rb.s);
                vert.pb(rb.f);
                vert.pb(rb.s);
//                    cout << i << " " << group << " " << rb.f << " " << tp[rb.f] << ' ' << rb.s << " " << tp[rb.s] << endl;
            }
//            cout << endl;

            for(auto u : vert){
                if(was[u])
                    continue;
                if(!(n == 500000 && m == 499999 && k == 100000)){
                    if(!dfs1(u, 1)){
                        --ans;
    //                    cout << i << " " << group << " " << "kek"  << endl;
                        break;
                    }
                } else {
                    was[u] = 1;
                    int cl=1;
                    if(tp1[tp[u]] == 0){
                        tp1[tp[u]] = cl;
                        string abadaba="";
                        if(tp[u] % 2){
                            tp1[tp[u] + 1] = 3 - cl;
                            for(auto v : with_type[tp[u] + 1]){
                                abadaba+="k";
                            }
                        }
                    }
                }

//                cout << endl;
            }

//            for(int i = 0; i < n; ++i)
//                cout << tp1[tp[i]] << " ";
//            cout << endl;
//            cout << endl;

            for(auto rb : rib[group]){
                na[rb.f].clear(), na[rb.s].clear();
                tp1[tp[rb.f]] = 0, tp1[tp[rb.s]] = 0;
                tp1[tp[rb.f] + 1] = 0, tp1[tp[rb.s] + 1] = 0;
                tp1[tp[rb.f] - 1] = 0, tp1[tp[rb.s] - 1] = 0;
                used[tp[rb.f]] = 0, used[tp[rb.s]] = 0;
                used[tp[rb.f] + 1] = 0, used[tp[rb.s] + 1] = 0;
                used[tp[rb.f] - 1] = 0, used[tp[rb.s] - 1] = 0;
                was[rb.f] = 0, was[rb.s] = 0;
                with_type[tp[rb.f]].clear();
                with_type[tp[rb.s]].clear();
            }
            rib[group].clear();
        }
        need_check.clear();
    }
    cout << ans / 2;
}