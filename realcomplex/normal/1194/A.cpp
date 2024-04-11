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
    int testc;
    cin >> testc;
    for(int tt = 0 ;tt < testc; tt ++ ){
        int n, x;
        cin >> n >> x;
        cout << 2 * x << "\n";
    }
    return 0;
}