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

string clr(string s){
    string tmp = "";
    for(char x : s){
        if(x == 'B') tmp += "B";
    }
    for(char x : s){
        if(x != 'B') tmp += x;
    }
    return tmp;
}

string go(string s){
    string res = "";
    for(char x : s){
        if(res.size() && res.back() == x) res.pop_back();
        else res.pb(x);
    }
    return res;
}

void solve(){
    string s1, s2; cin >> s1 >> s2;
    s1 = clr(s1); s2 = clr(s2);
    if(go(s1) == go(s2)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}