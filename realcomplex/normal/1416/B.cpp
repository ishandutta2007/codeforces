#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e4 + 10;
ll A[N];

struct O{
    int i;
    int j;
    int x;
};

void solve(){
    int n;
    cin >> n;
    ll S = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        S += A[i];
    }
    if(S % n != 0){
        cout << "-1\n";
        return;
    }
    S /= n;
    vector<O> qi;
    ll ad;
    ll need;
    for(int i = 2; i <= n; i ++ ){
        need = (i - A[i] % i) % i;
        qi.push_back({1, i, need});
        A[1] -= need;
        A[i] += need;
        ad = (A[i] / i);
        A[i] = 0;
        qi.push_back({i, 1, ad});
        A[1] += i * ad;
    }
    for(int i = 2; i <= n; i ++ ){
        qi.push_back({1, i, S});
    }
    cout << qi.size() << "\n";
    for(auto o : qi){
        cout << o.i << " " << o.j << " " << o.x << "\n";
    }
    return;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}