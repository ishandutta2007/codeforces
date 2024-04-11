#include <bits/stdc++.h>
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

const int nax = 1005;

vector<vector<ll> > ans;
int n;

ll a[nax];

void dodaj(int i, int j){
    a[i] += a[j];
    ans.pb({1, i, j});
}

void odej(int j, int i){
    a[j] -= a[i];
    ans.pb({2, i, j});
}

void dbg(){
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void solve(){
    ans.clear();
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i+=2){
        for(int j=0;j<2;j++){
            dodaj(i,i+1);
            odej(i+1,i);
            dodaj(i,i+1);

        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
    }
    //dbg();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}