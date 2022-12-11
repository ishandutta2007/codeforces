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
    vector<ll> cand;
    ll mlt = 1ll;
    int sz = 0;
    for(int i = 1; i < n; i ++){
        if(__gcd(i, n) == 1){
            mlt *= i;
            mlt %= n;
            if(mlt == 1) sz = cand.size();
            cand.push_back(i);
        }
    }
    cout << sz + 1 << "\n";
    for(int j = 0 ; j <= sz; j ++ ){
        cout << cand[j] << " ";
    }
    cout << "\n";

    return 0;
}