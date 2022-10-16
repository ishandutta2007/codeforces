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
ll a[nax];
int n, k;
int cnt[nax];
int big = 0;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    big = 0;
    cin >> n >> k;
    for(int i=0;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] <= n){
            cnt[a[i]] += 1;
        }
        else big++;
    }
    sort(a + 1, a + n + 1);
    int dif = 1;
    for(int i=2;i<=n;i++){
        dif += (a[i] != a[i - 1]);
    }

    FenwickTree tri(2 * n + 3);
    FenwickTree tri2(2 * n + 3);
    int luki = 0;
    int ans = 2e9;
    for(int i=0;i<=n;i++){
        luki += (cnt[i] == 0);
    }

    map<int,int> debil;
    for(int i=1;i<=n;i++){
        if(a[i] > n){
            debil[a[i]] += 1;
        }
    }
    for(pii cur : debil){
        tri.add(cur.nd, cur.nd);
        tri2.add(cur.nd, 1);
    }


    for(int i=n;i>=0;i--){
         luki -= (cnt[i] == 0);
        bool dbg = (i == 3);
        if(max(luki, cnt[i]) <= k){
            int zjem = k - cnt[i];
            //if(dbg) cout << "W" << zjem << endl;
            int lo = 0;
            int hi = n;

            if(tri.sum(0, n) <= zjem){
                //cout << "C" << endl;
                //cout << "W" << dif - (cnt[i] != 0) + luki << "\n";
                //cout << tri2.sum(0, n) - i << "\n";
                //cout << dif - (cnt[i] != 0) << "\n";
                //cout << tri2.sum(0, n) << "\n";
                //cout << i << "\n";
                //if(dbg) cout << "A" << endl;
                ans = min(ans, (dif - (cnt[i] != 0) + luki) - tri2.sum(0, n) - i);
            }

            else{
                while(lo + 1 < hi){
                    int mid = (lo + hi) / 2;
                    int cc = tri.sum(0, mid);
                    if(cc <= zjem) lo = mid;
                    else hi = mid;
                }
                //if(dbg) cout << "Z" << lo << " " << hi << endl;
                int fiSm = lo;
                if(tri.sum(0, lo) <= zjem) fiSm = hi;
                fiSm--;
                //if(dbg){
                //    for(int c=0;c<=6;c++) cout << c << " " << tri.sum(c, c) << "\n";
                //    exit(0);
                //}
                //if(dbg) cout << "X" << fiSm << endl;
                int taken = tri.sum(0, fiSm);
                //if(dbg) cout << "XD" << taken << "\n";
                zjem -= taken;
                int didi = (dif - (cnt[i] != 0)) + luki - tri2.sum(0, fiSm);
                //cout << "XD" << didi << "\n";
                int wantMore = zjem / (fiSm + 1);
                didi -= wantMore;
                //cout << "CO" << (dif - (cnt[i] != 0)) << " " << luki << " " << tri2.sum(0, fiSm) << "\n";
                //cout << "A" << didi << " " << i << endl;
                //cout << "B" << zjem << " " << fiSm << "\n";
                //cout << "C" << tri2.sum(0, fiSm) << "\n";
                //cout << "D" << wantMore << "\n";
                ans = min(ans, didi - i);
            }

        }
        //break;
        //cout << "B" << endl;
        if(cnt[i] != 0){
            tri.add(cnt[i], cnt[i]);
            tri2.add(cnt[i], 1);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}