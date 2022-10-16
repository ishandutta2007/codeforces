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



bool eq(pii one, pii two){
    if(one == two) return true;
    swap(one.st, one.nd);
    return (one == two);
}

bool taken[222];

void solve(){
    int n,k; cin >> n >> k;
    fill(taken, taken + n * 2 + 3, false);
    vector<pii> a;
    for(int i=1;i<=k;i++){
        int x, y; cin >> x >> y;
        a.pb(mp(x, y));
        taken[x] = true;
        taken[y] = true;
    }
    int jest = 0;
    vector<int> xd;
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            xd.clear();
            xd.pb(a[i].st);
            xd.pb(a[i].nd);
            xd.pb(a[j].st);
            xd.pb(a[j].nd);
            sort(xd.begin(), xd.end());
            bool niema = false;
            for(int c=0;c<4;c++){
                if(eq(mp(xd[c], xd[(c+1)%4]), a[i])) niema = true;
            }
            if(!niema) jest++;
        }
    }
    for(pii cur : a){
        int ile[2] = {0, 0};
        int flag = 0;
        for(int i=1;i<=2*n;i++){
            if(i == cur.st || i == cur.nd) flag ^= 1;
            if(taken[i]) continue;
            ile[flag]++;
        }
        jest += min(ile[0], ile[1]);
    }
    jest += (n - k) * (n - k - 1) / 2;
    cout << jest << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}