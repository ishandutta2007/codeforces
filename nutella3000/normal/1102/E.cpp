#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
    //freopen('","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int,int> last;
    int n;
    cin >> n;
    ll ans = 1;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = n - 1;i >= 0;i--) {
        if (last[a[i]] == 0) last[a[i]] = i;
    }
    int ind = 0;
    for(int i = 0;i < n;i++) {
        if (i > ind) ans *= 2;
        ind = max(ind,last[a[i]]);
        ans %= 998244353;
    }
    cout << ans;
 }