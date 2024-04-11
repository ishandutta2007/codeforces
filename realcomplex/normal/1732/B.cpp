#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int pre[N];
int X[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n + 1; i ++ ){
        pre[i] = 0;
    }
    char f;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        X[i] = f - '0';
    }
    for(int i = 1; i < n; i ++ ){
        if(X[i] != X[i + 1]) pre[i] = 1;
        else pre[i] = 0;
        pre[i] += pre[i - 1];
    }
    pre[n] = pre[n - 1];
    int pp, qq;
    int res = n;
    for(int l = 0 ; l <= n; l ++ ){
        if(l == 0)
            pp = 0;
        else
            pp = pre[l - 1];
        if(l > 0 && X[1] == 1) pp ++ ;
        qq = pre[n]-pre[l];
        if(l != n && X[l + 1] != ((pp + 1) % 2)) qq ++ ;
        res = min(res, pp + qq);
    }
    cout << res << "\n";
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