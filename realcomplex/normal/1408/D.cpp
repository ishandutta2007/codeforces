#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2010;
int a[N], b[N], c[N], d[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> c[i] >> d[i];
    }
    int a0 = 0, b0 = 0;
    vector<pii> qq;
    int m0 = 0, m1 = 0;
    for(int i = 1;i <= n; i ++){
        a0 = 0, b0 = 0;
        for(int j = 1; j <= m ; j ++ ){
            a0 = max(0,c[j]-a[i]+1);
            b0 = max(0,d[j]-b[i]+1);
            qq.push_back(mp(a0, b0));
        }
    }
    sort(qq.begin(), qq.end());
    for(int i = (int)qq.size() - 2; i >= 0 ; i -- ){
        qq[i].se = max(qq[i].se, qq[i+1].se);
    }
    int sol = min(qq.back().fi, qq[0].se);
    for(int i = 0 ; i + 1 < qq.size(); i ++ ){
        sol = min(sol, qq[i].fi + qq[i+1].se);
    }
    cout << sol << "\n";
    return 0;
}