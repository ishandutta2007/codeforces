#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
int par[N];

int fin(int x){
    if(par[x] == x) return x;
    return par[x]=fin(par[x]);
}

void unite(int a, int b){
    a = fin(a);
    b = fin(b);
    if(a==b) return;
    par[a]=b;
}

struct C{
    ll keep;
    int st;
    int id;
    bool operator<(const C &F) const {
        return keep < F.keep;
    }
};

vector<int> L[N];

ll A[N], B[N];

int main(){
    fastIO;
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i ++ )
        par[i] = i;
    for(int i = 1; i <= m; i ++ )
        cin >> A[i];
    for(int i = 1; i <= n; i ++ ){
        cin >> B[i];
    }
    int s;
    int c;
    ll qs;
    vector<C> gy;
    ll total = 0;
    ll mx = 0;
    for(int i = 1; i <= m; i ++ ){
        cin >> s;
        for(int j = 1; j <= s; j ++ ){
            cin >> c;
            qs = A[i] + B[c];
            gy.push_back({qs, i, c});
            total += qs;
        }
    }
    sort(gy.begin(), gy.end());
    while(!gy.empty()){
        if(L[gy.back().id].empty()){
            L[gy.back().id].push_back(gy.back().st);
            mx += gy.back().keep;
        }
        else{
            if(fin(L[gy.back().id].back()) != fin(gy.back().st)){
                unite(L[gy.back().id].back(), gy.back().st);
                mx += gy.back().keep;
                L[gy.back().id].push_back(gy.back().st);
            }
        }

        gy.pop_back();
    }
    cout << total - mx << "\n";
    return 0;
}