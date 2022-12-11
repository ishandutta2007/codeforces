#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<int>> a;
int n, m;

void rec(vector<bool> can){
    for(int i = 1; i < n; i ++ ){
        vector<int> ids;
        for(int j = 0 ; j < m ; j ++ ){
            if(a[i][j] != a[0][j]){
                ids.push_back(j);
            }
        }
        if(ids.size() >= 5) return;
        if(ids.size() == 3){
            for(int p = 0 ; p < ids.size(); p ++ ){
                if(can[ids[p]]){
                    vector<bool> sha(m, false);
                    for(int j = 0 ; j < ids.size(); j ++ ){
                        if(j != p){
                            if(can[ids[j]]) sha[ids[j]]=true;
                        }
                    }
                    int pv = a[0][ids[p]];
                    a[0][ids[p]] = a[i][ids[p]];
                    rec(sha);
                    a[0][ids[p]] = pv;
                }
            }

            return;
        }
        if(ids.size() == 4){
            for(int p = 0 ; p < ids.size(); p ++ ){
                for(int q = 0; q < ids.size(); q ++ ){
                    if(can[ids[p]] && can[ids[q]]){
                        vector<bool> sha(m, false);
                        for(int t = 0; t < ids.size(); t ++ ){
                            if(t != p && t != q){
                                if(can[ids[t]]){
                                    sha[ids[t]]=true;
                                }
                            }
                        }
                        int pa = a[0][ids[p]];
                        int pb = a[0][ids[q]];
                        a[0][ids[p]] = a[i][ids[p]];
                        a[0][ids[q]] = a[i][ids[q]];
                        rec(sha);
                        a[0][ids[p]] = pa;
                        a[0][ids[q]] = pb;
                    }
                }
            }
            return;
        }
    }
    cout << "Yes\n";
    for(int i = 0 ; i < m ; i ++ )
        cout << a[0][i] << " ";
    exit(0);
}

int main(){
    fastIO;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0 ; i < n; i ++) {
        a[i].resize(m);
        for(int j = 0 ; j < m ; j ++ ){
            cin >> a[i][j];
        }
    }
    vector<bool> att(m, true);
    rec(att);
    cout << "No\n";
    return 0;
}