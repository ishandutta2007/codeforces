#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
    int n;
    cin >> n;
    vector<pii> p(n);
    vector<pair<pii, int>> segs;//start, isopen
    vector<int> score(n, 0);
    foru(i, 0, n) {
        cin >> p[i].first >> p[i].second;
        segs.pb({{p[i].first, 1}, i});
        segs.pb({{p[i].second+1, 0}, i});

    }
    sort(segs.begin(), segs.end());
    int closed=0,opened=0;
    foru(i,0,2*n){
        if(segs[i].first.second){
            score[segs[i].second]+=closed;
            opened++;
        } else{
            score[segs[i].second]+=(n-opened);
            closed++;
        }
    }
    int bst=n;
    foru(i,0,n)bst=min(bst,score[i]);
    cout<<bst<<'\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}