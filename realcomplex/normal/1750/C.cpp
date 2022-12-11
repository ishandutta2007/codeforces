#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int a[N];
int b[N];

void solve(){
    int n;
    cin >> n;
    char f;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        a[i]=f-'0';
    }
    int p0 = 0, q0 = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        b[i]=f-'0';
        if(a[i] != b[i]){
            p0 ++ ;
        }
        else{
            q0 ++ ;
        }
    }
    if(p0 > 0 && q0 > 0){
        cout << "NO\n";
        return;
    }
    vector<pii> soln;
    if(q0 > 0){
        soln.push_back(mp(1, n));
        for(int i = 1; i <= n; i ++ ){
            a[i] ^= 1;
        }
    }

    int lef = -1;
    int flip = 0;
    for(int i = 1; i <= n; i ++ ){
        if(a[i] == 0){
            soln.push_back(mp(i, i));
            flip ^= 1;
        }
    }
    if(flip == 0){
        soln.push_back(mp(1, n));
    }
    else{
        soln.push_back(mp(1, 1));
        soln.push_back(mp(2, n));
    }
    cout << "YES\n";
    cout << soln.size() << "\n";
    for(auto p : soln){
        cout << p.fi << " " << p.se << "\n";
    }
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