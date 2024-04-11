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
    string s; cin >> s;
    int mini = 1e9;
    int maxi = -1e9;
    int cnt = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            maxi = i;
            mini = min(mini, i);
            cnt++;
        }
    }
    if(cnt == 0){
        cout << 0 << "\n";
        return;
    }
    if(maxi - mini + 1 == cnt){
        cout << 1 << "\n";
    }
    else cout << 2 << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}