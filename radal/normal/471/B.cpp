#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define X first
#define Y second
using namespace std;
const ll N=1e5;
ll h[N],cnt[N];
pair<ll,ll> ans[N];
int main(){
    ll n;
    cin >> n;
    rep (i,0,n){
        cin >> h[i];
        ans[i].X = h[i];
        ans[i].Y = i+1;
        cnt[h[i]-1]++;
    }
    sort (cnt,cnt+N);
    if (!(cnt[N-1] >= 3 || (cnt[N-1] == 2 && cnt[N-2] == 2))){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    sort (ans ,ans+n);
    rep (i,0,n){
        cout << ans[i].Y <<" ";
    }
    cout << endl;
    rep (i,1,n){
        if (ans[i].X == ans[i-1].X){
            swap(ans[i],ans[i-1]);
            break;
        }
    }
    rep (i,0,n){
        cout << ans[i].Y <<" ";
    }
    cout << endl;
    bool f=0;
    rep(i,1,n){
        if (ans[i].X == ans[i-1].X && !f) f = 1;
        else if (ans[i].X == ans[i-1].X){
            swap (ans[i],ans[i-1]);
            break;
        }
    }     
    rep (i,0,n){
          cout << ans[i].Y <<" ";
      }

    return 0;
}