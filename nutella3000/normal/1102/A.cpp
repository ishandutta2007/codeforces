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
    ll n;
    cin >> n;
    if ((n * (n + 1) / 2) % 2 == 0) cout << 0;
    else cout << 1;
}