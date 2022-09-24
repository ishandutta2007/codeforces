#include<set>

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }


int N, H, W;

int main() {
    scanf("%d%d%d", &W, &H, &N);
    set<int> Hs, Ws;
    Hs.insert(0); Hs.insert(H);
    Ws.insert(0); Ws.insert(W);

    multiset<int> Hm, Wm;
    Hm.insert(H);
    Wm.insert(W);
    
    REP ($, N) {
        char op[9]; int x;
        scanf("%s%d", op, &x);
        set<int>::iterator it;
        if (op[0] == 'H') {
            it = Hs.lower_bound(x);
            int r = *it, l = *(--it);
            Hm.erase(Hm.find(r-l));
            Hm.insert(r-x);
            Hm.insert(x-l);
            Hs.insert(x);
        } else {
            it = Ws.lower_bound(x);
            int r = *it, l = *(--it);
            Wm.erase(Wm.find(r-l));
            Wm.insert(r-x);
            Wm.insert(x-l);
            Ws.insert(x);
        }
        LL w = *Wm.rbegin();
        LL h = *Hm.rbegin();
        printf("%lld\n", w*h);

    }
    return 0;
}