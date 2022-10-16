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

int minX, maxX, minY, maxY;

int ask(int r, int c){
    cout << "? " << c << " " << r << endl;
    fflush(stdout);
    int x; cin >> x;
    assert(x >= 0);
    return x;
}

void ans(int a, int b, int c, int d){
    cout << "! " << a << " " << b << " " << c << " " << d << endl;
    fflush(stdout);
    exit(0);
}

const int n = 1e9;
int dn;

bool UnderEq(int r){
    int ac = ask(r, 1);
    if(ac > dn) return false;
    int dif = dn - ac;
    if(dif == n - r) return true;
    return false;
}

void solve(){
    dn = ask(n, 1);
    // NAJWIEKSZY W (DOLNY)
    int lo = 1;
    int hi = n;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(UnderEq(mid)) hi = mid;
        else lo = mid;
    }
    int LowPoziom = lo;
    if(UnderEq(hi)) LowPoziom = hi;
    int dif = dn - (n - LowPoziom);
    int LeftPion = dif + 1;

    int xd = ask(1, 1);
    xd -= (LeftPion - 1);
    int TopPoziom = xd + 1;

    xd = ask(1, n);
    xd -= (TopPoziom - 1);

    int RightPion = n - xd;
    ans(min(LeftPion, RightPion), min(TopPoziom, LowPoziom), max(LeftPion, RightPion), max(TopPoziom, LowPoziom));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}