#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int a[N];
ll pf[N];
ll sf[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        if(i % 2 == 0)
            ans += a[i];
        pf[i]=a[i];
        sf[i]=a[i];
        if(i>1)
            pf[i] += pf[i - 2];
    }
    for(int i = n - 3; i >= 0 ; i -- ){
        sf[i] += sf[i + 2];
    }
    for(int i = 0 ; i + 1 < n; i ++ ){
        ans = max(ans, pf[i] + sf[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}