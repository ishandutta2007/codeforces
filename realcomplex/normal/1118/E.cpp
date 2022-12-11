#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

int main(){
    fastIO;
    ll n, k;
    cin >> n >> k;
    if(k * (k - 1) >= n){
        cout << "YES\n";
        int d = 0;
        int c;
        for(int i = 0; i < n; i ++ ){
            if(i % k == 0)
                d ++ ;
            cout << (i % k) + 1 << " " << ((i + d) % k) + 1 << "\n";
        }
        return 0;
    }
    else{
        cout << "NO\n";
        return 0;
    }
    return 0;
}