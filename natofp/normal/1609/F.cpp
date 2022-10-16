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

const int nax = 1e6 + 5;
// BUILTIN MA BYC LL !
ll a[nax];
ll ile[nax];
int n;

ll ans = 0;

int cntMin[66];
int cntMax[66];

ll brut(){
    ll ac = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll mini = a[i];
            ll maxi = a[i];
            for(int k=i;k<=j;k++){
                mini = min(mini, a[k]);
                maxi = max(maxi, a[k]);
            }
            if(__builtin_popcountll(mini) == __builtin_popcountll(maxi)){
                cout << i << " " << j << endl;
            }
        }
    }
    cout << ac << endl;
}

void reku(int lo, int hi){
    if(lo == hi){
        ans += 1;
        return;
    }
    int mid = (lo + hi) / 2;
    reku(lo, mid);
    reku(mid + 1, hi);
    // z prawej sa WIEKSZE
    // z prawej tylko min
    fill(cntMax, cntMax + 66, 0);
    int wsk1 = mid + 1;
    int wsk2 = mid;
    ll miniRight = a[mid + 1];
    ll maxiRight = a[mid + 1];
    ll maxi1 = a[mid];
    ll maxi2 = a[mid];
    for(int i=mid+1;i<=hi;i++){
        miniRight = min(miniRight, a[i]);
        maxiRight = max(maxiRight, a[i]);
        // tylko mini ?
        // OSTRO WIEKSZE Z LEWEJ MAJA BYC
        while(wsk1 > lo && a[wsk1 - 1] > miniRight){
            wsk1 -= 1;
            maxi1 = max(maxi1, a[wsk1]);
            cntMax[__builtin_popcountll(maxi1)] += 1;
        }
        while(wsk2 >= lo && maxi2 <= maxiRight){
            cntMax[__builtin_popcountll(maxi2)] -= 1;
            wsk2 -= 1;
            maxi2 = max(maxi2, a[wsk2]);
        }
        if(wsk1 <= wsk2){
            ans += cntMax[__builtin_popcountll(miniRight)];
        }
    }

    //if(dbg) cout << "WA" << ans << endl;
    //cout << ans << endl;

    // z LEWEJ MIN, z PRAWEJ MAX, =
    fill(cntMax, cntMax + 66, 0);
    wsk1 = mid + 1;
    wsk2 = mid;
    miniRight = a[mid + 1];
    maxiRight = a[mid + 1];
    ll mini1 = a[mid];
    ll mini2 = a[mid];
    for(int i=mid+1;i<=hi;i++){
        bool dbg = (i == 4);
        miniRight = min(miniRight, a[i]);
        maxiRight = max(maxiRight, a[i]);
        // tylko mini ?
        // Z LEWEJ MIN, Z PRAWEJ MAX
        while(wsk1 > lo && a[wsk1 - 1] <= maxiRight){
            wsk1 -= 1;
            mini1 = min(mini1, a[wsk1]);
            //if(dbg) cout << "CO" << __builtin_popcountll(mini1) << endl;
            cntMax[__builtin_popcountll(mini1)] += 1;
        }
        while(wsk2 >= lo && mini2 > miniRight){
            cntMax[__builtin_popcountll(mini2)] -= 1;
            //if(dbg) cout << "ER" << __builtin_popcountll(mini2) << endl;
            wsk2 -= 1;
            mini2 = min(mini2, a[wsk2]);
        }
        //cout << "WA" << wsk1 << " " << wsk2 << endl;
        //cout << "WA" << i << " " << wsk1 << " " << wsk2 << endl;
        //cout << "WA" << i << " " << wsk1 << " " << wsk2 << endl;
        //cout << ans << endl;
        if(wsk1 <= wsk2){
            ans += cntMax[__builtin_popcountll(maxiRight)];
        }
    }
    //cout << ans << endl;
    //cout << ans << endl;
    //if(dbg) cout << "CO" << ans << endl;
    // z prawej OBA

    fill(cntMax, cntMax + 66, 0);
    ll mini = a[mid + 1];
    ll maxi = a[mid + 1];
    int wsk = mid + 1;
    for(int i=mid+1;i<=hi;i++){
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
        while(wsk > lo && a[wsk - 1] > mini && a[wsk - 1] <= maxi){
            wsk -= 1;
        }
        if(__builtin_popcountll(mini) == __builtin_popcountll(maxi)){
            ans += (mid + 1 - wsk);
        }
    }


    fill(cntMax, cntMax + 66, 0);
    mini = a[mid];
    maxi = a[mid];
    wsk = mid;
    for(int i=mid;i>=lo;i--){
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
        while(wsk < hi && a[wsk + 1] >= mini && a[wsk + 1] < maxi){
            wsk += 1;
        }
        if(__builtin_popcountll(mini) == __builtin_popcountll(maxi)){
            ans += (wsk - mid);
        }
    }

}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        ile[i] = __builtin_popcountll(a[i]);
    }
    reku(1, n);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    //brut();

    return 0;
}