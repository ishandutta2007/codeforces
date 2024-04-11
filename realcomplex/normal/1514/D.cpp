#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)3e5 + 100;
int A[N];
vector<int> ord[N];

int cnt(int x, int l, int r){
    int rr = upper_bound(ord[x].begin(), ord[x].end(), r) - ord[x].begin();
    rr -- ;
    int lv = lower_bound(ord[x].begin(), ord[x].end(), l) - ord[x].begin();
    if(lv <= rr)
        return rr - lv + 1;
    return 0;
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        ord[A[i]].push_back(i);
    }
    int li, ri;
    int sz;
    int mx;
    int ele;
    int aa;
    int cha;
    for(int iq = 0; iq < q; iq ++ ){
        cin >> li >> ri;
        sz = ri - li + 1;
        mx = 0;
        for(int it = 1; it <= 40 ; it ++ ){
            ele = ((int)rng() % sz + sz) % sz;
            aa = A[li + ele];
            mx = max(mx, cnt(aa, li, ri));
        }
        if(mx > (sz + 1) / 2){
            cout << mx - (sz - mx) << "\n";
        }
        else{
           cout << 1 << "\n";
        }
    }
    return 0;
}