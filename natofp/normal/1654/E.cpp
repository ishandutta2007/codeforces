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
int a[nax];
int n;
const int SQRT = 600;
int cnt[nax * (SQRT + 5) * 2];
const int OFSET = nax * (SQRT + 5);

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int stay = 0;
    for(int i=-SQRT;i<=SQRT;i++){
        for(int j=1;j<=n;j++){
            int cur = a[j] + j * i;
            cnt[OFSET + cur] += 1;
            stay = max(stay, cnt[OFSET + cur]);
        }
        for(int j=1;j<=n;j++){
            int cur = a[j] + j * i;
            cnt[OFSET + cur] -= 1;
        }
    }

    for(int i=1;i<=n;i++){
        int go = min(n, i + 300 + 1);
        for(int j=i+1;j<=go;j++){
            int dif = a[j] - a[i];
            int len = j - i;
            if(abs(dif) % len != 0) continue;
            cnt[OFSET + dif / len] += 1;
            stay = max(stay, cnt[OFSET + dif / len] + 1);
        }
        for(int j=i+1;j<=go;j++){
            int dif = a[j] - a[i];
            int len = j - i;
            if(abs(dif) % len != 0) continue;
            cnt[OFSET + dif / len] -= 1;
        }
    }

    cout << n - stay << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}