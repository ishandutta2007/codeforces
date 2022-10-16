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
    if(n == 1){
        cout << s << s << "\n";
        return;
    }
    if(s[1] >= s[0]){
        cout << s[0] << s[0] << "\n";
        return;
    }
    int id = -1;
    for(int i=1;i<n;i++){
        if(s[i] > s[i - 1]){
            id = i - 1;
            break;
        }
    }
    if(id == -1) id = n - 1;
    for(int i=0;i<=id;i++) cout << s[i];
    for(int i=id;i>=0;i--) cout << s[i];
    cout << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}