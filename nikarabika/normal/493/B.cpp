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

int main(){
    ios_base::sync_with_stdio(false);
    int n, last;
    cin >> n;
    vector <int> vv[2];
    ll scr[2] = {0, 0};
    reu(i, 1, n){
        ll a;
        cin >> a;
        if(a < 0){
            a *= -1;
            scr[1] += a;
            vv[1].pb(a);
            last = 1;
        }
        else{
            scr[0] += a;
            vv[0].pb(a);
            last = 0;
        }
    }
    if(scr[1] > scr[0])
        cout << "second" << endl;
    else if (scr[1] < scr[0])
        cout << "first" << endl;
    else{
        vector <int> sss;
        sss = vv[0];
        sort(vv, vv + 2);
        if(sss == vv[0] && sss != vv[1])
            cout << "second" << endl;
        else if(sss == vv[1] && sss != vv[0])
            cout << "first" << endl;
        else if(last == 0)
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
    return 0;
}