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

int main(){
    fastIO;
    ll n, k;
    cin >> n >> k;
    ll p=1;
    ll cur;
    while(1){
        cur = p * (p + 1) / 2 - (n - p);
        if(cur == k){
            cout << n - p;
            return 0;
        }
        p++;
    }
    return 0;
}