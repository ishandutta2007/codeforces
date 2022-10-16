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
#define mt make_tuple

using namespace std;

const int nax = 1e5 + 5;
ll d;
int n;
ll a[nax];

void solve(){
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int l = 1;
    int r = n;
    int ans = 0;
    while(l <= r){
        ll cur = a[r];
        ll need = ((d + 1 + cur - 1)) / cur;
        if(need > r - l + 1) break;
        ans++;
        r--;
        need--;
        while(need--) l++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}