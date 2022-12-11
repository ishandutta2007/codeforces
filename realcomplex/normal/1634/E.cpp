#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 10;

map<int, int> cmp;
int id;

int add(int x){
    if(cmp.count(x)) return cmp[x];
    id ++ ;
    cmp[x] = id;
    return id;
}

struct edge{
    int idx;
    int nex;
    int to;
};

vector<edge> T[N];
vector<int> soln[N];
vector<int> inq[N];
bool vis[N];


int main(){
    fastIO;
    int m;
    cin >> m;
    int n;
    int x;
    for(int iq = 1; iq <= m; iq ++ ){
        cin >> n;
        for(int ii = 0; ii < n; ii ++ ){
            cin >> x;
            x=add(x);
            T[iq].push_back({iq, ii, m + x});
            T[m + x].push_back({iq, ii, iq});
            soln[iq].push_back(0);
            inq[iq].push_back(0);
        }
    }
    for(int im = 1; im <= id; im ++ ){
        if(T[m + im].size() % 2 == 1){
            cout << "NO\n";
            return 0;
        }
    }
    int node;
    int nex;
    for(int id = 1; id <= m; id ++ ){
        if(vis[id]) continue;
        vector<int> que;
        vector<edge> qq;
        que.push_back(id);
        while(!que.empty()){
            node = que.back();
            vis[node]=true;
            while(!T[node].empty()){
                if(inq[T[node].back().idx][T[node].back().nex]){
                    T[node].pop_back();
                }
                else{
                    break;
                }
            }
            if(T[node].empty()){
                if(!qq.empty()){
                    if(qq.back().to <= m){
                        soln[qq.back().idx][qq.back().nex] = 1;
                    }
                    qq.pop_back();
                }
                que.pop_back();
            }
            else{
                nex = T[node].back().to;
                inq[T[node].back().idx][T[node].back().nex] = true;
                que.push_back(nex);
                qq.push_back(T[node].back());
            }
        }
    }
    cout << "YES\n";
    for(int id = 1; id <= m; id ++ ){
        for(auto x : soln[id]){
            if(x == 0) cout << "L";
            else cout << "R";
        }
        cout << "\n";
    }
    return 0;
}