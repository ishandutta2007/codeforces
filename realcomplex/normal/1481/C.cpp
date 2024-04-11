#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int A[N];
int B[N];
vector<int> nd[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++ ){
        nd[i].clear();
    }
    int eq = -1;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i  ++ ){
        cin >> B[i];
        if(A[i] != B[i]){
            nd[B[i]].push_back(i);
            eq = i;
        }
    }
    vector<int> c(m);
    vector<int> sol(m);
    for(int i = 0 ; i < m ; i ++ ){
        cin >> c[i];
    }
    int was = -1;
    for(int i = 1; i <= n; i ++ ){
        if(B[i] == c.back() && B[i] != A[i] && was == -1) was = i;
    }
    for(int i = 1; i <= n; i ++ ){
        if(B[i] == c.back() && was == -1) was = i;
    }
    if(was == -1){
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < m ; i ++ ){
        if(nd[c[i]].empty() || i + 1 == m){
            sol[i] = was;
        }
        else{
            sol[i] = nd[c[i]].back();
            nd[c[i]].pop_back();
        }
        A[sol[i]] = c[i];
    }
    for(int i = 1; i <= n; i ++ ){
        if(A[i] != B[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(auto x : sol)
        cout << x << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int ti = 1; ti <= tc; ti ++ ){
        solve();
    }
    return 0;
}