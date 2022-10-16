#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;
const int nax = 2e5 + 5;

int lewe[nax];
int prawe[nax];

void solve(){
    int n,l,r; cin>>n>>l>>r;
    set<int> alive;
    for(int i=1;i<=l;i++){
        int x; cin >> x;
        lewe[x]++;
        alive.insert(x);
    }
    for(int i=1;i<=r;i++){
        int x; cin >> x;
        prawe[x]++;
        alive.insert(x);
    }
    int ans = 0;
    for(int x : alive){
        int p = min(lewe[x], prawe[x]);
        lewe[x] -= p;
        prawe[x] -= p;

        while(l > r && lewe[x] >= 2){
            lewe[x] -= 2;
            ans++;
            l -= 2;
        }
        while(r > l && prawe[x] >= 2){
            prawe[x] -= 2;
            ans++;
            r -= 2;
        }
    }
    int c0 = 0;
    int c1 = 0;
    for(int x : alive){
        c0 += lewe[x];
        c1 += prawe[x];
    }
    //cout << c0 << " "<<c1<<endl;
    ans += (max(c1,c0) - min(c1, c0)) / 2;
    ans += (c0 + c1) / 2;
    cout << ans << "\n";
    for(int x : alive){
        lewe[x] = 0;
        prawe[x] = 0;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}