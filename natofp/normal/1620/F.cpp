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

using namespace std;

const int nax = 1e6 + 5;
const int inf = 1e9;
int a[nax];
int n;

map<tuple<int, int, int>, pair<pii, int> > pop;

set<pii> alive;
set<pii> nxt;

void go(int id, int val){
    for(pii was : alive){
        if(val < was.st && val < was.nd) continue;
        if(val < was.st){
            nxt.insert(mp(was.st, val));
            pop[make_tuple(id, was.st, val)] = mp(was, val);
        }
        else{
            nxt.insert(mp(val, was.nd));
            pop[make_tuple(id, val, was.nd)] = mp(was, val);
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    pop.clear();
    alive.clear();
    nxt.clear();
    alive.insert(mp(-a[1], -inf));
    pop[make_tuple(1, -a[1], -inf)] = mp(mp(0, 0), -a[1]);
    for(int i=2;i<=n;i++){
        int val = a[i];
        nxt.clear();
        go(i, val);
        go(i, -val);

        while(1){
            vector<pii> out;
            for(pii cur : nxt){
                bool ex = false;
                for(pii dom : nxt){
                    if(dom.st < cur.st && dom.nd < cur.nd) ex = true;
                    if(dom.st == cur.st && dom.nd < cur.nd) ex = true;
                    if(dom.st < cur.st && dom.nd == cur.nd) ex = true;
                }
                if(ex) out.pb(cur);
            }
            if(out.empty()) break;
            for(pii cur : out) nxt.erase(cur);
        }
        alive = nxt;
    }
    if(alive.empty()){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        vector<int> ans;
        int id = n;
        pii cur = (*alive.begin());
        while(id >= 1){
            auto go = pop[make_tuple(id, cur.st, cur.nd)];
            ans.pb(go.nd);
            cur = go.st;
            id -= 1;
        }
        reverse(ans.begin(), ans.end());
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}