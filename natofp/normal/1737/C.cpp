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

int cnt[2];
int rr[3];
int cc[3];
int n;


bool rog(pii cur){
    if(cur.st != 1 && cur.st != n) return false;
    if(cur.nd != 1 && cur.nd != n) return false;
    return true;
}

void solve(){
    cin >> n;
    cnt[0] = cnt[1] = 0;
    for(int i=1;i<=3;i++){
        int r, c; cin >> r >> c;
        cnt[(r + c) % 2]++;
        rr[i - 1] = r;
        cc[i - 1] = c;
    }

    int x, y; cin >> x >> y;
    int d = (x + y) % 2;
    int cent = 0;
    if(cnt[0] == 2) cent = 1;
    pii xd;
    for(int i=0;i<3;i++){
        if((rr[i] + cc[i]) % 2 == cent){
            xd = mp(rr[i], cc[i]);
        }
    }

    int rrr = abs(xd.st - x);
    int ccc = abs(xd.nd - y);

    if(rog(xd)){
        if(min(rrr, ccc) == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        return;
    }

    if(cent != d){
        cout << "YES" << "\n";
        return;
    }
    else{
        if(rrr % 2 == 0 && ccc % 2 == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}