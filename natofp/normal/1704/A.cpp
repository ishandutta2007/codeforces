#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;


void solve(){
    int n, m; cin >> n >> m;
    string s1; cin >> s1;
    string s2; cin >> s2;
    char need = s2[0];
    bool ex = false;
    for(int i=0;i<s1.size()-s2.size()+1;i++){
        if(s1[i] == need) ex = true;
    }
    string xd1 = s1.substr(s1.size() - s2.size() + 1, 100);
    string xd2 = s2.substr(1, 100);
    if(xd1 != xd2) ex = false;
    if(ex) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}