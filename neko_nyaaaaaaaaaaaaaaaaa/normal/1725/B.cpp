#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#define trace(x) cout << '>' << #x << ':' << x << "\n"
#define trace2(x,y) cout << '>' << #x << ':' << x << " | " << #y << ':' << y << "\n"
#define trace3(a,b,c) cout << #a << "=" << (a) << ", " << #b << "="<< (b) << ", " << #c << "=" << (c) << "\n"
#define trace4(a,b,c,d) cout << #a << "=" << (a) << ", " << #b << "=" << (b) << ", " << #c << "=" << (c) << ", " << #d << "=" << (d) << "\n"

#define finput freopen("input.txt", "r", stdin);
#define foutput freopen("output.txt", "w", stdout);

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
const int mod = 1e9+7;



signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, d;
    cin >> n >> d;
    d++;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(all(v));
    reverse(all(v));
    int ans = 0;
    int left = n;
    for (int i = 0; i < n; i++){
        int need = (d+v[i]-1)/v[i];
        if (need>left) break;
        ans++;
        left -= need;
    }

    cout << ans;

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/