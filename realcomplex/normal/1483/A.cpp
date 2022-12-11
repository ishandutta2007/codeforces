#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
int cnt[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> f;
        int k;
        for(int i = 1; i <= n; i ++ ){
            cnt[i]=0;
        }
        int x;
        for(int i = 0 ; i < m; i ++ ){
            cin >> k;
            f.push_back({});
            for(int j = 0; j < k ; j ++ ){
                cin >> x;
                f.back().push_back(x);
            }
        }
        vector<int> sol(m);
        for(int i = 0; i < m; i ++ ){
            if(f[i].size() == 1){
                cnt[f[i][0]] ++ ;
                sol[i] = f[i][0];
                f[i].clear();
            }
        }
        int id;
        for(int i = 0 ; i < m ; i ++) {
            if(f[i].empty()) continue;
            id = f[i][0];
            for(auto x : f[i]){
                if(cnt[x] < cnt[id]){
                    id = x;
                }
            }
            cnt[id] ++ ;
            sol[i] = id;
        }
        bool valid = false;
        for(int i = 1; i <= n; i ++) {
            if(cnt[i] > (m + 1) / 2){
                valid = true;
            }
        }
        if(valid){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(auto x : sol)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}