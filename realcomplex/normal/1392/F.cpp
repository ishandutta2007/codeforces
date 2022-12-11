#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
ll h[N];


int main(){
    fastIO;
    int n;
    cin >> n;
    ll S = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> h[i];
        S += h[i];
    }
    ll sum = n * 1ll * (n - 1) / 2;
    ll times = (S-sum)/n;
    ll extra = (S-sum)%n;
    for(int i = 0 ; i < n; i ++ ){
        cout << i + times + (i < extra) << " ";
    }
    cout << "\n";
    return 0;
}