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

bool can(int x){
    int lo = 1;
    int hi = n;
    while(lo < hi){
        if(a[lo] == a[hi]){
            lo += 1;
            hi -= 1;
        }
        else{
            if(a[lo] == x) lo += 1;
            else if(a[hi] == x) hi -= 1;
            else return false;
        }
    }
    return true;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int lo = 1;
    int hi = n;
    while(lo < hi){
        if(a[lo] == a[hi]){
            lo += 1;
            hi -= 1;
        }
        else break;
    }
    if(lo >= hi){
        cout << "YES" << "\n";
        return;
    }
    vector<int> v;
    v.pb(a[lo]);
    v.pb(a[hi]);
    for(int x : v){
        if(can(x)){
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}