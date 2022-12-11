#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double d,l,v,v1;
    cin >> d >> l >> v >> v1;
    l-=d;
    double ans = l/(v+v1);
    cout << fixed << setprecision(7) << ans;
    return 0;
}