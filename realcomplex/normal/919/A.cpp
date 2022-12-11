#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pair<int,int> pii
#define abs(a) ((a<0) ? -a : a)
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);

int main(){
    fastIO;
    int n;
    ld m;
    cin >>n >> m;
    ld a,b;
    ld ans = (ld)1e9;
    while(n--){
        cin >> a >> b;
        ans = min(ans,(m/b)*a);
    }
    cout << fixed << setprecision(7) << ans;
    return 0;
}