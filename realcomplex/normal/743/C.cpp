#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n==1){cout << -1; return 0;}
    cout << n << " " << n+1 << " " << (n*(n+1));
    return 0;
}