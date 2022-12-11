#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> T[N];
int c[N], q[N], w[N];
int sol[N];

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    for(int i = 1; i <= n + 1; i ++ ){
        T[i].clear();
        c[i] = q[i] = w[i] = 0;
    }
    int e;
    int nt=0;
    for(int i = 1; i <= n; i ++ ){
        cin >> e;
        T[e].push_back(i);
        c[e] ++ ;
    }
    priority_queue<pii> ord;
    for(int i = 1; i <= n + 1; i ++ ){
        if(c[i] > 0)ord.push(mp(c[i], i));
        else{
            nt = i;
        }
    }
    int cl;
    int idx;
    int tx = 0, ty = 0;
    while(tx < x){
        cl = ord.top().fi;
        idx = ord.top().se;
        ord.pop();
        q[idx] ++ ;
        w[idx] ++ ;
        sol[T[idx].back()] = idx;
        T[idx].pop_back();
        tx ++ ;
        ty ++ ;
        if(cl > 0){
            ord.push(mp(cl - 1, idx));
        }
    }
    while(!ord.empty())
        ord.pop();
    for(int i = 1; i <= n + 1; i ++ ){
        if(q[i] < c[i]){
            ord.push(mp((n-x)-(c[i]-w[i]), i));
        }
    }
    while(ty < y){
        if(ord.empty()){
            cout << "NO\n";
            return;
        }
        cl = ord.top().fi;
        idx = ord.top().se;
        ord.pop();
        q[idx] ++ ;
        ty ++ ;
        if(cl > 0){
            if(q[idx] < c[idx])
                ord.push(mp(cl - 1, idx));
        }
    }
    int shift = 0;
    vector<int> ind;
    vector<int> ele;
    for(int i = 1; i <= n + 1; i ++ ){
        if(q[i] - w[i] > (n-x) - (c[i]-w[i])){
            cout << "NO\n";
            return;
        }
        for(auto x : T[i]){
            ind.push_back(x);
        }
        for(int j = c[i] - q[i]; j > 0 ; j -- ){
            ele.push_back(nt);
        }
        for(int j = q[i] - w[i]; j > 0 ; j -- ){
            ele.push_back(i);
        }
        shift = max(shift, (c[i]-w[i]));
    }
    for(int i = 0; i < ind.size(); i ++ ){
        sol[ind[i]] = ele[(i+shift)%(int)ele.size()];
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ )
        cout << sol[i] << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}