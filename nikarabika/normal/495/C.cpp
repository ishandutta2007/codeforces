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

string s;
vector <int> ans;
int v, rc, ro;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> s;
    rep(i, s.size()){
        if(s[i] == '#'){
            v = i;
            rc = 0;
            ro = 0;
            s[i] = ')';
            ans.pb(1);
        }
        else if(s[i] == ')')
            rc ++;
        else
            ro ++;
    }
    if(ro > rc){
        cout << -1 << endl;
        return 0;
    }
    ans.pop_back();
    s[v] = '#';
    int o = 0, c = 0;
    rep(i, s.size()){
        if(s[i] == ')')
            c ++;
        else if(s[i] == '(')
            o ++;
        else{
            ans.pb(o - c - (rc - ro));
            if(ans.back() <= 0){
                cout << -1 << endl;
                return 0;
            }
            c += ans.back();
            goto lab;
        }
        if(o < c){
            cout << -1 << endl;
            return 0;
        }
        lab:
        ;
    }
    rep(i, ans.size())
        cout << ans[i] << endl;
    return 0;
}