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

int main(){
    fastIO;
    int test_case;
    cin >> test_case;
    for(int t = 0 ; t < test_case ; t ++ ){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = false;
        for(int i = n - 11; i >= 0 ; i -- ){
            if(s[i] == '8')
                ok = true;
        }
        cout << (ok?"YES\n":"NO\n");
    }
    return 0;
}