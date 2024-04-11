#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    map<string, int> pari;
    string qq;
    for(int i = 0 ; i < n; i ++ ){
        qq.clear();
        qq.push_back(a[i]);
        qq.push_back(b[n-i-1]);
        sort(qq.begin(), qq.end());
        //cout << qq << "!\n";
        pari[qq] ++;
    }
    int odd = 0;
    for(auto x : pari){
        if(x.se % 2 == 1){
            if(x.fi[0] == x.fi[1]) odd ++ ;
            else odd += 2;
        }
    }
    if(odd == 0 || (odd == 1 && n % 2 == 1))
        cout << "YES\n";
    else
        cout << "NO\n";

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