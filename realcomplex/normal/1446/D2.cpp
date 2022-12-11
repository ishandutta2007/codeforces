#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int M = N * 2 + 10;
const int K = 400;

vector<int> pos[N];
int A[N];
int cnt[M];
int las[M];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        pos[A[i]].push_back(i);
    }
    vector<pii> C;
    for(int i = 1; i <= n; i ++ ){
        C.push_back(mp(pos[i].size(), i));
    }
    sort(C.begin(), C.end());
    int idx = C.back().se;
    int soln = 0;
    int cur;
    int sz;
    int pa, qa;
    int cac;
    int R;
    int L;
    int st;
    int go;
    int nex;
    int vis;
    for(int i = 1; i <= n; i ++ ){
        if(i == idx) continue;
        if(pos[i].size() >= K){
            for(int id = 0 ; id <= n * 2; id ++ ){
                las[id]=-1;
            }
            las[n] = 0;
            cur = 0;
            for(int id = 1; id <= n; id ++ ){
                if(A[id] == i) cur ++ ;
                else if(A[id] == idx) cur -- ;
                if(las[cur + n] != -1){
                    soln = max(soln, id - las[cur + n]);
                }
                else{
                    las[cur + n] = id;
                }
            }
        }
        else{
            sz = pos[i].size();
            for(int id = 0; id < sz; id ++ ){
                pa = id - 1;
                qa = lower_bound(pos[idx].begin(), pos[idx].end(), pos[i][id]) - pos[idx].begin();
                st = qa;
                qa -- ;
                cac = 1;
                while(pa >= 0 || qa >= 0){
                    if(pa >= 0 && (qa < 0 || pos[i][pa] > pos[idx][qa])){
                        cac ++ ;
                        pa -- ;
                    }
                    else{
                        cac -- ;
                        qa -- ;
                    }
                    if(abs(cac) > sz) break;

                    L = 1;
                    if(pa >= 0)
                        L = max(L, pos[i][pa] + 1);
                    if(qa >= 0)
                        L = max(L, pos[idx][qa] + 1);
                    if(cac >= 0){
                        if(st + cac - 1 >= pos[idx].size()) continue;
                        go = pos[idx][st + cac - 1];
                        nex = n + 1;
                        if(id + 1 < sz)
                            nex = pos[i][id + 1];
                        R = n;
                        if(go <= nex){
                            R = min(R, nex - 1);
                            if(st + cac < pos[idx].size())
                                R = min(R, pos[idx][st + cac] - 1);
                            soln = max(soln, R - L + 1);
                        }
                    }

                }
            }
        }
    }
    cout << soln << "\n";
    return 0;
}