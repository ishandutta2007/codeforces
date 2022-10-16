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
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == 1 || i == n){
                if(j % 2 == 1){
                    cout << "1";
                }
                else cout<<"0";
            }
            else{
                if(j != 1 && j != m){
                    cout<<"0";
                }
                else{
                    if(i%2==1 && i+1!=n) cout<<"1";
                    else cout<<"0";
                }
            }
        }
        cout << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}