#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }




int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);

    int n;
    scanf("%d", &n);
    
    int mx = 1023;
    int mnx = 0;
    int m0 = 0;
    int m1 = 0;
    
    for (int i = 0; i < n; ++i) {
    	char t;
    	int num;
    	scanf("\n%c%d", &t, &num);
    	int nnum = (~num) & 1023;
    	if (t == '|') {
    		m1 |= num;
    		mx &= nnum;
    		m0 &= nnum;
    		mnx &= nnum;
    	} else if (t == '&') {
    		m0 |= nnum & 1023;
    		m1 &= num;
    		mx &= num;
    		mnx &= num;
    	} else {
    		int mmx = mx, mmnx = mnx, mm0 = m0, mm1 = m1;
    		mx = mmx & nnum | mmnx & num;
    		mnx = mmnx & nnum | mmx & num;
    		m0 = mm0 & nnum | mm1 & num;
    		m1 = mm1 & nnum | mm0 & num;
    	}
    }
    
    cout << 3 << "\n";
    cout << "^ " << mnx << "\n" << "| " << m1 << "\n" << "& " << ((~m0) & 1023) << "\n";    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}