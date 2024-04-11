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

int sc[2][150];
vector <pair<int, pie> > ans;

int main(){
	ios_base::sync_with_stdio(false);
    string s[2];
    cin >> s[0] >> s[1];
    int n;
    cin >> n;
    rep(i, n){
        int a, c;
        char b, d;
        int scr, team;
        cin >> a >> b >> c >> d;
        if(b == 'a')
            team = 1;
        else
            team = 0;
        if(d == 'r')
            scr = 2;
        else
            scr = 1;
        if(sc[team][c] < 2){
            sc[team][c] += scr;
            if(sc[team][c] >= 2)
                ans.pb(mp(a, mp(team, c)));
        }
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size())
        cout << s[ans[i].p2.p1] << ' ' << ans[i].p2.p2 << ' ' << ans[i].p1 << endl;
	return 0;
}