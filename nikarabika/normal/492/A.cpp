#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

#define F(x) = x * (x - 1) * (x - 2) / 6

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x = 1;
    while(1){
        if(x * (x + 1) * (x + 2) / 6 <= n && (x + 3) * (x + 2) * (x + 1) / 6 > n){
            cout << x << endl;
            return 0;
        }
        x ++;
    }
    return 0;
}