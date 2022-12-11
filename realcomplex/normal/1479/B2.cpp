#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
int A[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    set<pii> sol; // a -> sol
    set<pii> low; // sol -> a
    int vso = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    low.insert(mp(-1,1));
    sol.insert(mp(1,-1));
    int cv;
    int best;
    int pv;
    for(int i = 2; i <= n; i ++ ){
        cv = (A[i] != A[i-1]);
        auto it = sol.begin();
        best = (int)1e9;
        for(int q = 0; q < 4; q ++ ){
            if(it == sol.end()) break;
            best = min(best, (it->fi) + (A[i] != (it->se)) + vso);
            it++;
        }
        auto vv = low.lower_bound(mp(A[i-1], -(int)1e9));
        auto qq = low.lower_bound(mp(A[i], -(int)1e9));
        if(qq != low.end() && qq->fi == A[i]){
            best = min(best, (qq->se) + (qq->fi != A[i]) + vso);
        }
        if(vv != low.end() && vv->fi == A[i-1]){
            best = min(best, (vv->se) + (vv->fi != A[i]) + vso);
            pv = vv->se;
            low.erase(mp(A[i-1],pv));
            sol.erase(mp(pv,A[i-1]));
        }
        vso += cv;
        low.insert(mp(A[i-1],best-vso));
        sol.insert(mp(best-vso,A[i-1]));
    }
    auto pq = sol.begin();
    cout << (pq->fi) + vso << "\n";
    return 0;
}