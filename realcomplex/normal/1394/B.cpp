#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int K = 9;
const int Z = K * K;

bitset<Z> nx[K][K];
vector<pii> I[N];
vector<pii> T[N];
int force[K];
int has[K][K];

int k;
vector<vector<pii>> conds;
int answ = 0;

void brute(vector<int> cc){
    if(cc.size() == k) {
        for(int i = 0 ; i < k; i ++ ){
            for(int a = 0; a < k; a ++ ){
                if(nx[i][cc[i]][a * k + cc[a]])
                    return;
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < k ; i ++ )
            cnt += has[i][cc[i]];
        if(cnt != conds.size()) return;
        answ ++ ;
        return;
    }
    int f = cc.size();
    for(int i = 0 ; i <= f; i ++ ){
        if(force[f] != -1 && force[f] != i) continue;
        cc.push_back(i);
        brute(cc);
        cc.pop_back();
    }
}

int num[K][K];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m >> k;
    int u, v, w;
    for(int j = 0 ; j < k ; j ++ ){
        force[j]=-1;
    }
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v >> w;
        T[u].push_back(mp(w, v));
    }
    for(int i = 1; i <= n; i ++ ){
        sort(T[i].begin(), T[i].end());
        for(int j = 0 ; j < T[i].size(); j ++ ){
            I[T[i][j].se].push_back(mp((int)T[i].size() - 1, j));
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(I[i].size() == 0) continue;
        if(I[i].size() == 1){
            if(force[I[i][0].fi] != -1){
                if(force[I[i][0].fi] != I[i][0].se){
                    cout << "0\n";
                    return 0;
                }
            }
            force[I[i][0].fi] = I[i][0].se;
        }
        else{
            bitset<Z> vse;
            for(auto p : I[i]){
                num[p.fi][p.se] ++ ;
                vse[p.fi * k + p.se]=1;
            }
            for(auto p : I[i]){
                if(num[p.fi][p.se] == 1)
                    vse[p.fi * k + p.se] = 0;
                nx[p.fi][p.se] |= vse;
                if(num[p.fi][p.se] == 1)
                    vse[p.fi * k + p.se] = 1;
            }
            for(auto p : I[i]){
                num[p.fi][p.se]--;
            }
        }
        conds.push_back(I[i]);
        for(auto x : I[i]){
            has[x.fi][x.se] ++ ;
        }
    }
    brute({});
    cout << answ << "\n";
    return 0;
}