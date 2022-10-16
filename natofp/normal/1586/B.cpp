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

const int nax = 1e5 + 5;
int a[nax][3];
int n, m;

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++) cin >> a[i][j];
    }
    set<int> xd;
    for(int i=1;i<=n;i++) xd.insert(i);
    for(int i=1;i<=m;i++){
        xd.erase(a[i][1]);
    }
    int ac = (*xd.begin());
    for(int i=1;i<=n;i++){
        if(i != ac){
            cout << i << " " << ac << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}