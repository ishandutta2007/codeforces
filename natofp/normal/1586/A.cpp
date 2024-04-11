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

bool comp(int x){
    if(x < 2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return true;
    }
    return false;
}

void solve(){
    vector<int> a;
    int n; cin >> n;
    int s = 0;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        s += x;
        a.pb(x);
    }
    if(comp(s)){
        cout << n << "\n";
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        return;
    }
    int ou = -1;
    for(int i=1;i<=n;i++){
        if(a[i - 1] % 2 == 1) ou = i;
    }
    cout << n - 1 << "\n";
    for(int i=1;i<=n;i++){
        if(i != ou) cout << i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}