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
vector<ll> a, b;
int n;

int c[nax];
int d[nax];

ll go(vector<ll> a, vector<ll> b){
    if(min(a.size(), b.size()) == 0){
        ll sum = 0;
        for(ll x : a) sum += x;
        for(ll x : b) sum += x;
        return sum;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll sum = a[0];
    int p1 = 1;
    int p2 = 0;
    int sz1 = a.size();
    int sz2 = b.size();
    reverse(a.begin() + 1, a.end());
    reverse(b.begin(), b.end());
    int last = 0;
    while(p1 < sz1 || p2 < sz2){
        if(p1 == sz1){
            for(int i=p2;i<sz2;i++){
                sum += b[i];
                if(last == 0) sum += b[i];
                last = 1;
            }
            return sum;
        }
        else if(p2 == sz2){
            for(int i=p1;i<sz1;i++){
                sum += a[i];
                if(last == 1) sum += a[i];
                last = 0;
            }
            return sum;
        }
        else{
            if(last == 0){
                sum += b[p2] * 2;
                p2++;
                last = 1;
            }
            else{
                sum += a[p1] * 2;
                p1++;
                last = 0;
            }
        }
    }
    return sum;
}

void solve(){
    a.clear(); b.clear();
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=1;i<=n;i++){
        if(c[i] == 0) a.pb(d[i]);
        else b.pb(d[i]);
    }
    cout << max(go(a, b), go(b, a)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}