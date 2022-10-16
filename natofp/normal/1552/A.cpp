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


void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string xd = s;
    sort(xd.begin(), xd.end());
    int ac = 0;
    for(int i=0;i<n;i++) ac += (xd[i] == s[i]);
    cout << n - ac << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}