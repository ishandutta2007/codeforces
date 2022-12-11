#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> bits(n);
    vector<int> cnt(n);
    char f;
    for(int i = 0 ; i < n; i ++ ){
        cin >> f;
        bits[i] = (f - '0');
        bits[i] ^= (k & 1);
    }
    for(int i = 0 ; i < n; i ++ ){
        if(bits[i] == 0 && k > 0){
            bits[i] = 1;
            k -- ;
            cnt[i] ++ ;
        }
    }
    cnt[n - 1] += k;
    k %= 2;
    if(k) bits[n - 1] = 0;
    for(auto x : bits) cout << x;
    cout << "\n";
    for(auto x : cnt) cout << x << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}