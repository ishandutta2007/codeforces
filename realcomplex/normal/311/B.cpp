#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int P = 101;
const ll inf = (ll) 4e18;

ll s[N];
ll cat[N];
ll pref[N];
ll dp[P][N];

struct Line{
    ll a;
    ll b;
    ll ps;
};

ll dv(ll x, ll y){
    return (x/y) - ((x^y)<0 && x%y != 0);
}

ll intersectx(Line A, Line B){
    return dv(A.b-B.b,B.a-A.a);
}

int main(){
    fastIO;
    int n, m, p;
    cin >> n >> m >> p;
    if(p > m){
        cout << 0;
        return 0;
    }
    for(int i = 2; i <= n; i ++ ){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int id;
    ll tm;
    for(int i = 1 ; i <= m ; i ++ ){
        cin >> id >> tm;
        cat[i] = tm - s[id];
    }
    sort(cat + 1, cat + m + 1);
    for(int i = 1; i <= m; i ++ ){
        pref[i] = pref[i-1] + cat[i];
    }
    for(int i = 0; i < P; i ++ ) for (int j = 0 ; j < N ; j ++ ){
        dp[i][j] = inf;
    }
    dp[0][0] = 0;
    Line cur;
    int sz;
    for(int i = 1; i <= p ; i ++ ){
        deque<Line> Hull;
        for(int j = 1; j <= m; j ++ ){
            cur.a = j;
            cur.b = -dp[i-1][j-1]-pref[j-1];
            cur.ps = inf;
            while(Hull.size() > 1){
                sz = Hull.size();
                if(Hull[sz - 2].ps >= intersectx(Hull[sz - 1], cur)){
                    Hull[sz - 2].ps = intersectx(Hull[sz - 2], cur);
                    Hull.pop_back();
                }
                else{
                    break;
                }
            }
            if(!Hull.empty()){
                sz = Hull.size();
                Hull[sz - 1].ps = intersectx(Hull[sz - 1], cur);
            }
            Hull.push_back(cur);
            while(Hull.front().ps < cat[j])
                Hull.pop_front();
            dp[i][j] = min(dp[i][j], -(cat[j] * Hull.front().a + Hull.front().b) + cat[j] * (j+1) - pref[j]);
        }
    }
    cout << dp[p][m];
    return 0;
}