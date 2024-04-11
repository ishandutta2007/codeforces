#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for(ll i=l; i<r; i++)
using namespace std;
const ll N=1e5;
ll l[6];
ll cnt[N];
int main(){
    ll t;
  //  cin >> t;
    rep (i,0,6){
        cin >> l[i];
        cnt[l[i]]++;
    }
    sort (cnt,cnt+N);
    if (cnt[N-1] < 4){
        cout << "Alien";
        return 0;
    }
    if (cnt[N-2] == 2 || cnt[N-1] == 6){
        cout << "Elephant";
        return 0;
    }
    cout << "Bear";
    return 0;
}