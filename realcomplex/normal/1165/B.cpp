#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n; i ++ )
        cin >> a[i];
    sort(a, a + n);
    int k = 1;
    for(int i = 0 ; i < n; i ++ ){
        if(a[i] >= k){
            a[i] -= k;
            k ++ ;
        }
    }
    cout << k-1;
    return 0;
}