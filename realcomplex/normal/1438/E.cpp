#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
ll A[N];
ll p[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    set<pii> cand;
    ll soln = 0;
    int lf, rf;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        p[i] = (p[i - 1] + A[i]);
        if(i >= 3){
            cand.insert(mp(A[i-2] + p[i - 2], i - 2));
            auto it = cand.lower_bound(mp(p[i - 1] - A[i], -1));
            while(it != cand.end()){
                lf = it->se;
                rf = i;
                if(p[rf-1] - p[lf] == (A[lf]^A[rf])) soln ++ ;
                it ++ ;
            }
        }
    }
    cout << soln << "\n";
    return 0;
}