#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const int MAXK = 5000;

bool ciur[MAXK + 1];
vector <int> primes;

inline void sieve() {
    for(int i = 2; i * i <= MAXK; i++) {
        if(ciur[i] == 0) {
            for(int j = i * i; j <= MAXK; j += i) {
                ciur[j] = 1;
            }
        }
    }
    for(int i = 2; i <= MAXK; i++) {
        if(ciur[i] == 0) {
            primes.push_back(i);
        }
    }
}

vector < pair <int, int> > divi[MAXK + 1];
int fr[MAXK + 1], curSub[MAXK + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fr[x]++;
    }

    auto get = [&](int n, int k) {
        int ans = 0, pw = k;
        while(pw <= n) {
            ans += n / pw;
            pw *= k;
        }
        return ans;
    };

    sieve();

    for(i = 1; i <= MAXK; i++) {
        if(fr[i]) {
            for(auto it : primes) {
                if(i >= it) {
                    divi[i].push_back({it, get(i, it)});
                    //cerr << it << " " << get(i, it) << "  ";
                }
            }
            //cerr << "\n";
        }
    }

    ll ans = 0;
    int l = 1, r = MAXK;

    while(true) {
        for(auto it : primes) {
            curSub[it] = 0;
        }

        for(i = 1; i <= MAXK; i++) {
            if(divi[i].size()) {
                curSub[divi[i].back().first] += fr[i];
            }
        }

        int mx = 0, id;
        for(auto it : primes) {
            if(curSub[it] > mx) {
                mx = curSub[it];
                id = it;
            }
        }

        //cerr << id << " " << mx << " " << ans << "\n";

        if(mx < n / 2 + 1) {
            for(i = 1; i <= MAXK; i++) {
                int cur = 0;
                for(auto it : divi[i]) {
                    cur += it.second;
                }
                ans += 1LL * cur * fr[i];
            }
            break;
        }

        l = -1;
        for(i = 1; i <= MAXK; i++) {
            if(divi[i].empty()) continue;

            if(divi[i].back().first == id) {
                l = (l == -1 ? i : l);
                r = i;
                divi[i].back().second--;
                if(divi[i].back().second == 0) {
                    divi[i].pop_back();
                }
            }
            else {
                int cur = 0;
                for(auto it : divi[i]) {
                    cur += it.second;
                }
                ans += 1LL * cur * fr[i];
                divi[i].clear();
            }
        }

        ans += n - mx;
    }

    cout << ans;

    return 0;
}