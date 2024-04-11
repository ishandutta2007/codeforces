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
vector<int> pos;
const int BLOCK = 200;

unordered_map<int, int> cnt;

ll ch(ll x){
    return (x * (x - 1)) / 2;
}

void solve(){
    string s; cin >> s;
    n = s.size();
    pos.pb(0);
    for(int i=1;i<=n;i++){
        a[i] = s[i - 1] - '0';
        if(a[i] == 1) pos.pb(i);
    }
    pos.pb(n + 1);
    ll ans = 0;
    int c = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == 1) c++;
        else c = 0;
        ans += c;
    }
    for(int k=1;k<=BLOCK;k++){
        cnt.clear();
        cnt[0]++;
        int p = 0;
        for(int i=1;i<=n;i++){
            if(a[i] == 1) p -= k;
            else p++;
            cnt[p]++;
        }
        for(pii cur : cnt){
            ans += ch(cur.nd);
        }
    }

    for(int cnt=1;cnt<=n/BLOCK;cnt++){
        for(int j=cnt;j<pos.size() - 1;j++){
            int zeros = pos[j] - pos[j - (cnt - 1)] + 1 - cnt;
            int lenL = pos[j - (cnt - 1)] - pos[j - cnt] - 1;
            int lenR = pos[j + 1] - pos[j] - 1;
            int len = zeros + cnt - 1;
            int xd = min(lenL, lenR);
            int rem = len % cnt;
            for(int w=0;w<=lenL + lenR;w++){
                len++;
                rem++;
                if(rem == cnt){
                    rem = 0;
                    int prop = (len - cnt) / cnt;
                    if(prop > BLOCK){
                        ans += min(min(w, xd) , lenL + lenR - w) + 1;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}