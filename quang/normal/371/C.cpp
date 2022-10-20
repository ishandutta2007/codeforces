#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000001000ll
#define N

using namespace std;

string s;
int nc, nb, ns, pb, pc, ps;
long long r;
int ac, ab, as;

bool check(long long sl) {
    long long canb = max(0ll, (sl * ab - nb)) * pb;
    long long cans = max(0ll, (sl * as - ns)) * ps;
    long long canc = max(0ll, (sl * ac - nc)) * pc;
    return (canb + cans + canc <= r);
}

long long Tim() {
    long long l = 0, r = MAX;
    while(r - l > 1) {
        long long m = (l + r) >> 1;
        if(check(m)) l = m;
        else r = m;
    }
    return l;
}

int main() {
    //fi, fo;
    cin >> s;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    ac = ab = as = 0;
    for(int i = 0 ; i < (int)s.size(); i++) {
        if(s[i] == 'S') as++;
        if(s[i] == 'B') ab++;
        if(s[i] == 'C') ac++;
    }
    cout << Tim();
    return 0;
}