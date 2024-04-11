#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 2e5;
const int LOG = (int) 18;
const int SIGMA = 26;

string str, bad;

struct Data {
    int val1, val2;
    int p;
    bool operator <(const Data &other) const {
        if(val1 == other.val1)
            return val2 < other.val2;
        return val1 < other.val1;
    }
    bool operator !=(const Data &other) const {
        return !(val1 == other.val1 && val2 == other.val2);
    }
}v[MAXN + 1];

int lcp[MAXN + 1];

int P[MAXN + 1][LOG + 1];

int lg, n;

inline void SuffixArray() {
    int i;

    for(i = 0; i < n; i++)
        P[i][0] = str[i] - 'a' + 1;


    for(lg = 1; (1 << lg) <= 2 * n; lg++) {


        for(i = 0; i < n; i++) {
            if(i + (1 << (lg - 1)) < n)
                v[i] = {P[i][lg - 1], P[i + (1 << (lg - 1))][lg - 1], i};
            else
                v[i] = {P[i][lg - 1], 0, i};
        }


        sort(v, v + n);


        int val = 0;
        for(i = 0; i < n; i++) {
            if(i == 0)
                val++;
            else if(v[i] != v[i - 1])
                val++;

            P[v[i].p][lg] = val;
        }

    }
}

inline int get_lcp(int a, int b) {
    int ans = 0;

    for(int i = lg; i >= 0; i--) {
        if(P[a][i] == P[b][i] && (a + (1 << i)) <= n && (b + (1 << i)) <= n) {
            a += (1 << i);
            b += (1 << i);
            ans += (1 << i);
        }
    }

    return ans;
}


pair <int, int> ind[MAXN + 1];


inline void make_lcp() {
    int i;

    lg--;

    int sz = 0;

    for(i = 0; i < n; i++)
        if(bad[i] == '0')
            ind[++sz] = {P[i][lg], i};

    sort(ind + 1, ind + sz + 1);

    for(i = 1; i < sz; i++)
        lcp[i] = get_lcp(ind[i].second, ind[i + 1].second);

    n = sz - 1;

}

stack <int> stk;

int l[MAXN + 1], r[MAXN + 1];


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str >> bad;

    reverse(str.begin(), str.end());
    reverse(bad.begin(), bad.end());

    ll ans = 0;

    for(i = 0; i < n; i++)
        if(bad[i] == '0')
            ans = max(ans, (ll) n - i);

    SuffixArray();

    make_lcp();


    for(i = 1; i <= n; i++) {
        while(!stk.empty() && lcp[stk.top()] > lcp[i]) {
            r[stk.top()] = i - 1;
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()) {
        r[stk.top()] = n;
        stk.pop();
    }

    for(i = n; i >= 1; i--) {
        while(!stk.empty() && lcp[stk.top()] > lcp[i]) {
            l[stk.top()] = i + 1;
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()) {
        l[stk.top()] = 1;
        stk.pop();
    }

    for(i = 1; i <= n; i++)
        ans = max(ans, 1LL * lcp[i] * (r[i] - l[i] + 2));

    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}