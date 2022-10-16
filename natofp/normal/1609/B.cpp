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

const int nax = 3e5 + 5;
char s[nax];
bool czy[nax];
int cnt = 0;
int n;
bool jest(int pos){
    if(pos > n - 2 || pos < 1) return false;
    return (s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c');
}

void solve(){
    int q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    for(int i=1;i<=n-2;i++){
        if(jest(i)){
            cnt += 1;
        }
    }
    while(q--){
        int pos;
        cin >> pos;
        char x; cin >> x;
        int bylo = 0;
        for(int i=pos-2;i<=pos+2;i++){
            bylo += jest(i);
        }
        int teraz = 0;
        s[pos] = x;
        for(int i=pos-2;i<=pos+2;i++){
            teraz += jest(i);
        }
        cnt += (teraz - bylo);
        cout << cnt << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
   // cin >> tt;
    while(tt--) solve();

    return 0;
}