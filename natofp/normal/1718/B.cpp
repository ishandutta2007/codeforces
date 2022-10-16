#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

vector<int> fibs;
vector<int> cnt;

bool reku(int lastID, int nxtFib){
    bool zeros = true;
    for(int x : cnt){
        if(x != 0) zeros = false;
    }
    if(zeros) return true;
    if(nxtFib < 0) return false;
    vector<int> match;
    for(int i=0;i<cnt.size();i++){
        if(cnt[i] >= fibs[nxtFib] && i != lastID) match.pb(i);
    }
    if(match.size() > 2 || match.empty()) return false;
    for(int id : match){
        cnt[id] -= fibs[nxtFib];
        if(reku(id, nxtFib - 1)) return true;
        cnt[id] += fibs[nxtFib];
    }
    return false;
}

void solve(){
    fibs.clear();
    fibs.pb(1); fibs.pb(1);
    while(fibs.back() < 1e9){
        int sz = fibs.size();
        fibs.pb(fibs[sz - 1] + fibs[sz - 2]);
    }
    vector<int> cur;
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        cur.pb(x);
    }
    ll sum = 0;
    for(int x : cur) sum += x;
    int ptr = 0;
    while(sum > 0){
        sum -= fibs[ptr++];
        if(sum > 0 && ptr >= (int)fibs.size()){
            cout << "NO" << "\n";
            return;
        }
    }
    if(sum < 0){
        cout << "NO" << "\n";
        return;
    }
    cnt = cur;
    if(reku(-1, ptr - 1)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}