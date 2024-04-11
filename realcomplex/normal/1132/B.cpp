#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    ll t[n];
    ll sum = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> t[i];
        sum += t[i];
    }
    sort(t, t +n);
    reverse(t, t + n);
    int q;
    cin >> q;
    int id;
    for(int i = 0 ; i < q; i ++ ){
        cin  >> id;
        -- id;
        cout << sum - t[id] << "\n";
    }
    return 0;
}