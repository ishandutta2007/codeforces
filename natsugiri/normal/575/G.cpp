#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
//TEMPLATE {{{
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;

#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define all(c)           (c).begin(), (c).end()
#define perm(c)          sort(all(c)); for(bool _b = true; _b; _b = next_permutation(all(c)))
#define uniquenize(v)    (v).erase(unique(all(v)), (v).end())
#define sz(c)            int((c).size())

#ifdef HIBIKICHAN
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#else
#define dump(x)
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
inline int stoi(const string &s){return atoi(s.c_str());}
inline long long stoll(const string &s){return atoll(s.c_str());}

#endif

//}}}


vector<pair<int, int>> G[100000];

vector<pair<int, int>> H[100000], rH[100010];

int zdist[100000], zpar[100000];

int dist[100000];

pair<int, int> minval[100000], minval2[1000000];

vector<int> distv[100000];
bool ok[100000];
bool ok2[100000];

int par[100000];


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, m){
        int v, w, l;
        scanf("%d%d%d", &v, &w, &l);
        G[v].push_back({w, l});
        G[w].push_back({v, l});
    }

    memset(zdist, -1, sizeof(zdist));/*{{{*/
    queue<int> zq;
    zdist[n-1] = 0; zpar[n-1] = n-1;
    zq.push(n-1);

    while(!zq.empty()){
        int v = zq.front(); zq.pop();

        for(const auto&e : G[v]){
            int w = e.first;
            int l = e.second;
            if(l == 0 && zdist[w] == -1){
                zdist[w] = zdist[v] + 1;
                zpar[w] = v;
                zq.push(w);
            }
        }
    }/*}}}*/


    //0
    if(zdist[0] >= 0){/*{{{*/
        vector<int> ans;
        int v = 0;
        for(int i = 0; i < zdist[0]; i++){
            ans.push_back(v);
            v = zpar[v];
        }
        ans.push_back(v);

        printf("0\n%d\n", sz(ans));
        for(int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], " \n"[ans.size() == i+1]);
        return 0;
    }/*}}}*/

    //..0..0/*{{{*/
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < n; i++){
        if(zdist[i] >= 0){
            q.push(i);
            dist[i] = 0;
        }
    }

    while(!q.empty()){
        int v = q.front(); q.pop();

        for(const auto &e: G[v]){
            int w = e.first;
            int l = e.second;
            if(dist[w] == -1 || dist[w] == dist[v]+1){
                if(dist[w] == -1){
                    dist[w] = dist[v]+1;
                    q.push(w);
                }
                rH[v].push_back({w, l});
                H[w].push_back({v, l});
            }
        }
    }/*}}}*/

    //distv:0/*{{{*/
    for(int i = 0; i < n; i++){
        if(dist[i] >= 0){
            distv[dist[i]].push_back(i);
        }
    }/*}}}*/

    ///*{{{*/
    queue<int> q2;
    q2.push(0); ok2[0] = true;
    while(!q2.empty()){
        int v = q2.front(); q2.pop();
        for(const auto &e: H[v]){
            int w = e.first;
            if(!ok2[w]){
                ok2[w] = true;
                q2.push(w);
            }
        }
    }/*}}}*/


    memset(par, -1, sizeof(par));
    for(const int &v: distv[0]){
        ok[v] = true;
        par[v] = v;
        minval2[v] = {0, zdist[v]};
    }

    for(int i = 0; i < 100000; i++){
        minval[i] = {10, 10};
        for(const int &v: distv[i]){
            if(!ok[v] || !ok2[v]) continue;
            for(const auto &e: rH[v]){
                int w = e.first; int l = e.second;
                if(!ok2[w]) continue;
                minval[i] = min(minval[i], {l, minval2[v].second+1});
            }
        }

        for(const int &v: distv[i]){
            if(!ok[v]) continue;
            for(const auto &e: rH[v]){
                int w = e.first; int l = e.second;
                if(ok2[w] && minval[i] == make_pair(l, minval2[v].second+1)){
                    ok[w] = true;
                    par[w] = v;
                }
            }
        }
    }

    string ans;
    vector<int> ansv;
    int v = 0;
    for(int i = dist[0]-1; i >= 0; i--){
        ans += char(minval[i].first + '0');
        ansv.push_back(v);
        v = par[v];
    }

    reverse(all(ans));
    cout << ans << endl;
    ansv.push_back(v);
    //dump(ansv);
    //0
    int a = zdist[v];
    for(int i = 0; i < a; i++){
        v = zpar[v];
        ansv.push_back(v);
    }
    //dump(ansv);

    cout << ansv.size() << endl;
    rep(i, ansv.size()){
        cout << ansv[i] << " \n"[i+1 == ansv.size()];
    }
}