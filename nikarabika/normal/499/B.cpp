#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

map <string, string> M;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, m){
        string s, t;
        cin >> s >> t;
        if(t.size() < s.size())
            M[s] = t;
        else
            M[s] = s;
    }
    rep(i, n){
        string s;
        cin >> s;
        cout << M[s] << ' ';
    }
    cout << endl;
    return 0;
}