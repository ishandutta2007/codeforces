#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<pii,int> dp;

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int pi = 0, qi = 0;
        char f;
        int aa, bb;
        int g;
        dp.clear();
        for(int i = 1; i <= n; i ++ ){
            cin >> f;
            if(f == 'D'){
                pi ++ ;
            }
            else{
                qi ++ ;
            }
            aa = pi;
            bb = qi;
            g = __gcd(aa, bb);
            aa /= g;
            bb /= g;
            dp[mp(aa,bb)] ++ ;
            cout << dp[mp(aa,bb)] << " ";
        }
        cout << "\n";
    }
    return 0;
}