#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const int N = (int)2e5 + 9;
int px[N];
int sx[N];

int main(){
    fastIO;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int p = 0;
    for(int i = 1 ; i <= n; i ++ ){
        if(p < m && s[i - 1] == t[p]){
            p ++ ;
        }
        px[i] = p;
    }
    p = 0;
    for(int i = n; i >= 1; i -- ){
        if(p < m && s[i - 1] == t[m - p - 1]){
            p ++ ;
        }
        sx[i] = p;
    }
    int lf = 0, rf = n + 1;
    int mid;
    int li, ri;
    bool ok;
    while(lf + 1 < rf){
        mid = (lf + rf) / 2;
        ok = false;
        for(int i = 1; i <= n - mid + 1; i ++ ){
            li = i;
            ri = i + mid - 1;
            if(sx[ri + 1] + px[li - 1] >= m){
                ok = true;
            }
        }
        if(ok)
            lf = mid;
        else
            rf = mid;
    }
    cout << lf << "\n";
    return 0;
}