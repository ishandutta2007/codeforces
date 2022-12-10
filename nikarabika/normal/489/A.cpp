#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

vector <pie> ans;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a[n], b[n];
    rep(i, n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b, b+n);
    rep(i, n){
        FOR(j, i, n-1){
            if(a[j]==b[i] and i!=j and a[i]!=a[j]){
                ans.pb(mp(i, j));
                swap(a[i], a[j]);
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    rep(i, ans.size())
        cout<<ans[i].p1<<' '<<ans[i].p2<<endl;
    return 0;
}