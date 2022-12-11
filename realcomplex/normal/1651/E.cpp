#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3010;
vector<int> T[N];

bool has[N];

vector<int> ord;

void dfs(int u){
    ord.push_back(u);
    has[u]=true;
    for(auto x : T[u]){
        if(has[x]) continue;
        dfs(x);
    }
}

int n;

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n;
    int x, y;
    for(int i = 1; i <= n * 2; i ++ ){
        cin >> x >> y;
        T[x].push_back(y);
        T[y].push_back(x);
    }
    int li, ri;
    int lj, rj;
    ll res = 0;
    int C;
    int xi;
    int yi;
    bool can;
    int ai, bi;
    int aj, bj;
    ll W;
    for(int i = 1; i <= n * 2; i ++ ){
        has[i]=false;
    }
    int j;
    for(int i = 1; i <= n * 2; i ++ ){
        if(has[i]) continue;
        ord.clear();
        dfs(i);
        li = n;
        ri = 1;
        lj = n * 2;
        rj = n + 1;
        for(auto x : ord){
            if(x <= n) {
                li = min(li, x);
                ri = max(ri, x);
            }
            else{
                lj = min(lj, x);
                rj = max(rj, x);
            }
        }
        C = ord.size() / 2;
        res += li * 1ll * (n - ri + 1) * 1ll * (lj - n) * 1ll * (2 * n - rj + 1) * 1ll * C;
        for(int i = 0 ; i < ord.size(); i ++ ){
            li = n;
            ri = 1;
            lj = n * 2;
            rj = n + 1;
            for(int nx = 0; nx + 1 < ord.size(); nx ++ ){
                j = (i + nx) % ord.size();
                xi = ord[j];
                if(xi <= n){
                    li = min(li, xi);
                    ri = max(ri, xi);
                }
                else{
                    lj = min(lj, xi);
                    rj = max(rj, xi);
                }
                if(i > 0) yi = ord[i-1];
                else yi = ord[ord.size()-1];

                can = true;

                ai = 0;
                bi = n + 1;
                aj = n;
                bj = 2 * n + 1;

                if((yi >= li && yi <= ri) || (yi >= lj && yi <= rj)) can = false;
                else{
                    if(yi <= n){
                        if(yi < li) ai = max(ai, yi);
                        else bi = min(bi, yi);
                    }
                    else{
                        if(yi < lj) aj = max(aj, yi);
                        else bj = min(bj, yi);
                    }
                }


                if(j + 1 < ord.size()) yi = ord[j + 1];
                else yi = ord[0];

                if((yi >= li && yi <= ri) || (yi >= lj && yi <= rj)) can = false;
                else{
                    if(yi <= n){
                        if(yi < li) ai = max(ai, yi);
                        else bi = min(bi, yi);
                    }
                    else{
                        if(yi < lj) aj = max(aj, yi);
                        else bj = min(bj, yi);
                    }
                }
                if(can){
                    C = (nx + 1) / 2;
                    W = (li - ai) * 1ll * (bi - ri) * 1ll * (lj - aj) * 1ll * (bj - rj) * 1ll * C;
                    res += W;
                }
            }
        }

    }
    cout << res;
    return 0;
}