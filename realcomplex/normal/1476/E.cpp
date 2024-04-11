#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
map<string, int> idx;
int id;
vector<int> T[N];
vector<int> Q[N];
int ff[N];
string ash[N];
int k;
bool match(string ai, string bi){
    for(int r = 0; r < k ; r ++ ){
        if(ai[r] != bi[r] && bi[r] != '_') return false;
    }
    return true;
}

int vis[N];
vector<int> ord;

void dfs(int u){
    vis[u]=1;
    for(auto x : T[u]){
        if(vis[x]==1){
            cout << "NO\n";
            exit(0);
        }
        if(vis[x]==2) continue;
        dfs(x);
    }
    vis[u]=2;
    ord.push_back(u);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> ash[i];
        if(!idx.count(ash[i])){
            idx[ash[i]] = id;
            ff[id]=-1;
            id ++ ;
        }
        Q[idx[ash[i]]].push_back(i);
    }
    int dq;
    string fak;
    int ind;
    string nw;
    int nx;
    for(int i = 1; i <= m; i ++ ){
        cin >> fak >> dq;
        if(!match(fak, ash[dq])){
            cout << "NO\n";
            return 0;
        }
        ind = idx[ash[dq]];
        if(ff[ind] != -1 && ff[ind] != dq){
            ff[ind]=dq;
        }
        for(int lg = 0; lg < (1 << k); lg ++ ){
            nw.clear();
            for(int j = 0 ; j < k ; j ++ ){
                if((lg & (1 << j))){
                    nw.push_back('_');
                }
                else{
                    nw.push_back(fak[j]);
                }
            }
            if(idx.count(nw)){
                nx = idx[nw];
                if(nx != ind){
                    T[ind].push_back(nx);
                }
            }
        }
    }
    for(int i = 0 ; i < id; i ++ ){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());
    cout << "YES\n";

    for(auto q : ord){
        if(ff[q] != -1){
            cout << ff[q] << " ";
        }
        for(auto r : Q[q]){
            if(r != ff[q]){
                cout << r << " ";
            }
        }
    }
    return 0;
}