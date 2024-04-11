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

const int nax = 2e5 + 5;
int a[nax];
int n;
vector<int> values;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    values.clear();
    for(int i=1;i<=n;i++) values.pb(a[i]);
    int res = 0;
    for(int s=1;s<=n;s++){
        int dist = 0;
        int ans = 1;
        int pos = s;
        while(pos < n){
            if(dist == 0){
                auto it = upper_bound(values.begin(), values.end(), a[pos]);
                if(it == values.end()){
                    ans += (n - pos);
                    break;
                }
                else{
                    int gd = (int)(it - values.begin()) + 1;
                    ans += (gd - pos);
                    pos = gd;
                    dist = a[gd] - a[s];
                }
                continue;
            }
            auto it = lower_bound(values.begin(), values.end(), a[pos] + dist);
            if(it == values.end()){
                break;
            }
            else{
                ans += 1;
                dist = (*it) - a[s];
                pos = (int)(it - values.begin()) + 1;
            }
        }
        res = max(res, ans);
    }
    cout << n - res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}