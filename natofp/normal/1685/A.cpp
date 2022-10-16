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

const int nax = 2e5 + 5;
int a[nax];
int n;
map<int, int> cnt;
int b[nax];

void solve(){
    cnt.clear();
    cin >> n;
    int mx = 0;
    int kto = -1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > mx){
            mx = cnt[a[i]];
            kto = a[i];
        }
    }
    if(n % 2 == 1 || mx > n / 2){
        cout << "NO" << "\n";
        return;
    }
    sort(a + 1, a + n + 1);
    int ptr = 1;
    vector<int> ord;
    for(int i=1;i<=n;i+=2) ord.pb(i);
    for(int i=2;i<=n;i+=2) ord.pb(i);
    for(int x : ord){
        b[x] = a[ptr++];
        if(ptr == n + 1) ptr = 1;
    }
    for(int i=1;i<=n;i++){
        int bef = (i - 1);
        int za = i + 1;
        if(bef == 0) bef = n;
        if(za == n + 1) za = 1;
        if(b[i] < b[bef] && b[i] < b[za]) continue;
        if(b[i] > b[bef] && b[i] > b[za]) continue;
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    for(int i=1;i<=n;i++) cout << b[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}