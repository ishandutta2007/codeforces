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

int n;
string s;

string go(int xd){
    string ans = s;
    for(int i=0;i<(1<<n);i++){
        ans[i] = s[i ^ xd];
    }
    return ans;
}

const int nax = (1 << 9);
int wynik[nax][nax];

int b = 9;
int sz = (1 << b);
int ile;

void calc(int kt){
    int lo = kt * sz;
    int hi = (kt + 1) * sz - 1;
    string cur = "";
    for(int i=lo;i<=hi;i++) cur += s[i];
    vector<pair<string, int> > xdd;
    for(int x=0;x<sz;x++){
        string tmp = cur;
        for(int j=0;j<sz;j++){
            tmp[j] = cur[j ^ x];
        }
        xdd.pb(mp(tmp, x));
    }
    sort(xdd.begin(), xdd.end());
    int pos = 0;
    for(auto cur : xdd){
        //assert(cur.nd < nax);
        wynik[kt][cur.nd] = pos++;
    }
    for(int i=1;i<pos;i++){
        wynik[kt][xdd[i].nd] = (xdd[i].st != xdd[i - 1].st) + wynik[kt][xdd[i - 1].nd];
    }
}

void solve(){
    cin >> n;
    cin >> s;
    string ans = s;
    if(n <= 9){
        for(int i=0;i<(1<<n);i++) ans = min(ans, go(i));
    }
    else{
        ile = (1 << n) / sz;
        for(int i=0;i<ile;i++) calc(i);
        for(int i=0;i<ile;i++){
            vector<int> ord(ile);
            for(int j=0;j<ile;j++) ord[j] = (j ^ i);
            vector<int> opt;
            for(int j=0;j<ile;j++) opt.pb(1e9);
            int best = 0;
            //bool debug = (i == 2);
            for(int xo=0;xo<sz;xo++){
                vector<int> pos;
                for(int j=0;j<ile;j++) pos.pb(wynik[ord[j]][xo]);

                if(pos < opt){
                    opt = pos;
                    best = xo;
                }
            }
            //cout << "XD" << i << " " << best << "\n";
            int ful = (best) + (i * sz);
            //cout << "A" << ful << "\n";
            ans = min(ans, go(ful));
            // mamy opta

        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}