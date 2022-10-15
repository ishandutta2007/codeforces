#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int MN = 1e5+1000;
vector<pair<ll, ll> > v[MN];
ll et[MN];
ll aa[MN];
ll used[MN];
bool lol[MN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    vector<pair<ll, ll> > cute(k);
    for(int i = 0; i < m; ++i) {
        int q, w, e;
        cin>>q>>w>>e;
        --q,--w;
        v[q].push_back({w, e});
        v[w].push_back({q, e});
    }
    for(int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end());
    }
    for(int i = 1; i < n; ++i) et[i] = 1e15;
    priority_queue<pair<ll, ll> > jo;
    jo.push({0, 0});
    for(int i = 0; i < k; ++i) {
        ll q,w;
        cin>>q>>w;
        --q;
        cute[i] = {q, w};
        jo.push({-w, q});
        et[q] = min(et[q], w);
    }
    for(;jo.size(); ) {
        pair<ll, ll> q = jo.top();
        jo.pop();
        q.F = -q.F;
        if(lol[q.S]) continue;
        lol[q.S] = 1;
        //if(et[q.S] < q.F) continue;
        for(auto x: v[q.S]) {
            ll nd = q.F + x.S;
            ll np = x.F;
            if(et[np] >= nd) {
                aa[np]++; 
            }
            if(et[np] > nd) {
                aa[np] = 1;
                et[np] = nd;
                jo.push({-nd, np});
            }
        }
    }
    ll lol = 0;
    for(int i = 0; i < k; ++i) {
        if(et[cute[i].F] < cute[i].S) ++lol;
        else if(et[cute[i].F] == cute[i].S) {
            if(aa[cute[i].F]) ++lol;
            else if(used[cute[i].F]) {
                ++lol;
                
            }
            else ++used[cute[i].F];
        }
    }
    cout<<lol<<'\n';
}