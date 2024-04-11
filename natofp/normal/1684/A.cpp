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

int len(int x){
    if(x < 10) return 1;
    return 1 + len(x / 10);
}

void solve(){
    int x; cin >> x;
    vector<int> d;
    int tp = x;
    while(tp > 0){
        d.pb(tp % 10);
        tp /= 10;
    }
    if(d.size() == 2){
        cout << x % 10 << "\n";
    }
    else{
        sort(d.begin(), d.end());
        cout << d[0] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}