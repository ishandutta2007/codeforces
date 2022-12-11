#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 998244353;

void shuffle(int a, int b){
    vector<int> res;
    while(a > 0 && b > 0){
        res.push_back(b % 10);
        res.push_back(a % 10);
        b /= 10;
        a /= 10;
    }
    for(auto p : res)
        cout << p;
    cout << "\n";
}

int main(){
    fastIO;
    int n;
    cin >> n;
    ll a;
    ll pwr;
    ll sum = 0;
    int par = 0;
    ll d;
    ll nw;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a;
        pwr = 1;
        nw = a;
        while(a > 0){
            sum += (a % 10) * pwr * n;
            sum %= MOD;
            pwr *= 100ll;
            pwr %= MOD;
            a/=10;
        }
        a = nw;
        pwr = 10;
        while(a > 0){
            sum += (a % 10) * pwr * n;
            sum %= MOD;
            pwr *= 100ll;
            pwr %= MOD;
            a/=10;
        }
    }
    cout << sum;
    return 0;
}