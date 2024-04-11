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

const int AL = 26;
int cnt[AL];

int f(int x){
    return x*(x-1)/2;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string z;
    for(int i = 0 ; i < n; i ++ ){
        cin >> z;
        cnt[z[0] - 'a'] ++ ;
    }
    int res = 0;
    int v1, v2;
    for(int i = 0 ; i < AL; i ++ ){
        res += f(cnt[i]/2);
        res += f(cnt[i]-cnt[i]/2);
    }
    cout << res;
    return 0;
}