#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

ll n,k;

const int nax = 1e5 + 5;
const ll inf = 2e18;


void solve(){
    cin >> n >> k;
    vector<int> ans;
    // jest 2 ^ i , i elementowych
    for(int i=1;i<=n-61;i++) ans.pb(i);
    int last = 0;
    if(ans.size()) last = ans.back();
    // solve for small n : )
    if(n <= 61 && k > (1LL << (n-1))){
        cout << -1 << "\n";
        return;
    }
    int akt = last;
    int grupa = 1;
    while(k > 1){
        akt++;
        ll options = (1LL << (n - akt - 1));
        if(options < k){
            grupa++;
            k -= options;
        }
        else{

            for(int i=last + grupa;i>last;i--) ans.pb(i);
            //ans.pb(akt);
            last += grupa;
            grupa = 1;
        }
    }

    if(grupa != 1){
       for(int i=last + grupa;i>last;i--) ans.pb(i);
            //ans.pb(akt);
            last += grupa;
            grupa = 1;
    }

    for(int i=last+1;i<=n;i++) ans.pb(i);
    for(int x : ans) cout << x << " ";
    cout<<"\n";




}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}