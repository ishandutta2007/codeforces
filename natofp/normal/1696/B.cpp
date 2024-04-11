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
int a[nax];
int n, z;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int cnt = 0;
    for(int i=1;i<=n;i++) cnt += (a[i] == 0);
    if(cnt == n) cout << 0 << "\n";
    else{
        int l = 1;
        int r = n;
        while(a[l] == 0) l++;
        while(a[r] == 0) r--;
        int c = 0;
        for(int i=l;i<=r;i++) c += (a[i] == 0);
        if(c == 0) cout << 1 << "\n";
        else cout << 2 << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}