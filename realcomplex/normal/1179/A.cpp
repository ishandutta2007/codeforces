#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int p[n];
    deque<int> tt;
    int mx = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> p[i];
        mx = max(mx, p[i]);
        tt.push_back(p[i]);
    }
    vector<pii> answ1;
    while(tt[0] != mx){
        int a = tt[0];
        int b = tt[1];
        answ1.push_back(mp(a, b));
        tt.pop_front();
        tt.pop_front();
        tt.push_front(max(a,b));
        tt.push_back(min(a,b));
    }
    vector<pii> answ2;
    for(int i = 0 ; i < n-1; i ++ ){
        int a = tt[0];
        int b = tt[1];
        answ2.push_back(mp(a, b));
        tt.pop_front();
        tt.pop_front();
        tt.push_front(max(a,b));
        tt.push_back(min(a, b));
    }
    ll m;
    ll v1, v2;
    for(int i = 0 ; i < q; i ++ ){
        cin >> m;
        -- m;
        v1 = answ1.size();
        v2 = answ2.size();
        if(m < v1)
            cout << answ1[m].fi << " " << answ1[m].se << "\n";
        else{
            m -= v1;
            cout << answ2[m%v2].fi << " " << answ2[m%v2].se << "\n";
        }
    }
    return 0;
}