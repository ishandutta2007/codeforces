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
    string s, t; cin >> s >> t;
    int wsk = s.size() - 1;
    int wsk2 = t.size() - 1;

    while(wsk2 >= 0){
        if(s[wsk] == t[wsk2]){
            wsk--;
            wsk2--;
            continue;
        }
        else{
            wsk -= 2;
            if(wsk < 0){
                break;
            }
        }
    }
    if(wsk2 < 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}