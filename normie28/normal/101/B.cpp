#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
const int maxN = 1e5 + 10;
 
int poss_id[maxN];
int res, poss, toadd;
 
const int BEG = 1;
const int END = 0;
 
struct Seg {
    int pos, id, wat;
    Seg(int pos = 0, int id = 0, int wat = 0)
    : pos(pos), id(id), wat(wat) {}
 
    bool operator<(Seg const& o) const {
        if(pos == o.pos)
            return wat < o.wat;
        return pos > o.pos;
    }
};
 
Seg t[maxN * 2];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, n;
    cin>>N>>n;
    for(int a, b, i = 0; i < n; ++i) {
        cin>>a>>b;
        t[2 * i] = Seg{a, i, BEG};
        t[2 * i + 1] = Seg{b, i, END};
    }
    sort(t, t + 2 * n);
 
    poss = 1;
    bool reset = 0;
    for(int i = 0; i < 2 * n; ++i) {
        Seg const& s = t[i];
        if(s.pos != N && !reset)
            poss -= reset = 1;
        if(i && t[i].pos != t[i - 1].pos) {
            poss = (poss + toadd) % mod;
            toadd = 0;
        }
        if(s.wat == BEG) {
            poss = ((poss - poss_id[s.id]) % mod + mod) % mod;
            if(s.pos == 0)
                res = (res + poss_id[s.id]) % mod;
        } else {
            toadd = (toadd + (poss_id[s.id] = poss)) % mod;
        }
    }
    cout<<res;
}