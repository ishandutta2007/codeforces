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

using namespace std;

string daj(ll x){
    string res = "";
    while(x){
        res += ('0' + x % 2);
        x /= 2;
    }
    return res;
}

void go(string s1, string s2){
    for(int i=0;i<66;i++){
        for(int j=0;j<66;j++){
            string x1 = "", x2 = "";
            for(int k=0;k<i;k++) x1 += "1";
            for(int k=0;k<j;k++) x2 += "1";
            string p1 = x1 + s1 + x2;
            reverse(s1.begin(), s1.end());
            string p2 = x1 + s1 + x2;
            if(p1 == s2 || p2 == s2){
                cout << "YES" << "\n";
                exit(0);
            }
        }
    }
}

void solve(){
    ll x, y; cin >> x >> y;
    string s1 = daj(x);
    string s2 = daj(y);
    string tmp = s1;
    if(s1 == s2){
        cout << "YES" << "\n";
        return;
    }
    tmp = "1" + s1;
    go(tmp, s2);
    string xd = "";
    int wsk = 0;
    while(s1[wsk] == '0') wsk += 1;
    for(int i=wsk;i<s1.size();i++) xd += s1[i];
    go(xd, s2);
    cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}