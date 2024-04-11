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

const int nax = 2e6 + 5;
int a[nax];
int n;

int nxtBiggerEq[nax];
int prvSmallerEq[nax];
bool exist[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) exist[a[i]] = true;
    prvSmallerEq[0] = -1;
    for(int i=1;i<nax;i++){
        prvSmallerEq[i] = prvSmallerEq[i - 1];
        if(exist[i]) prvSmallerEq[i] = i;
    }
    nxtBiggerEq[nax - 1] = -1;
    for(int i=nax-2;i>=0;i--){
        nxtBiggerEq[i] = nxtBiggerEq[i + 1];
        if(exist[i]) nxtBiggerEq[i] = i;
    }
    ll ans = 1e18;
    for(ll x=1;x<=3e6;x++){
        if(a[1] > x * x + x) continue;
        ll low = max(x * x, 1ll * a[1]);
        ll high = x * x + x;

        ll lowBad = high + 1;
        ll highBad = x * x + x + x;
        ll obrot = 0;

        while(low <= high){
            lowBad = (x + obrot) * (x + obrot) + x + obrot + 1;
            highBad = (x + obrot) * (x + obrot) + x + x + obrot + obrot;
            bool dbg = (lowBad <= 100);

            ll wouldNeed = lowBad - low + a[1];
            if(wouldNeed >= nax) break;

            int nadwyzka = nxtBiggerEq[wouldNeed] - wouldNeed;
            if(nxtBiggerEq[wouldNeed] == -1){
                assert(prvSmallerEq[wouldNeed] != -1);
                ll space = wouldNeed - prvSmallerEq[wouldNeed] - 1;
                high = min(high, low + space);
                obrot++;
                continue;
            }
            else{
                if(nadwyzka > highBad - lowBad){
                    if(prvSmallerEq[wouldNeed] == -1){
                        obrot++;
                        continue;
                    }
                    else{
                        ll space = wouldNeed - prvSmallerEq[wouldNeed] - 1;
                        high = min(high, low + space);
                        obrot++;
                        continue;
                    }
                }
                else{
                    ll toGo = highBad - lowBad - nadwyzka + 1;
                    low += toGo;
                    continue;
                }
            }
        }
        if(low <= high){
            ans = low - a[1];
            break;
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