#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 2; i < n; i ++ ){
        sum += i * (i+1);
    }
    cout << sum;
    return 0;
}