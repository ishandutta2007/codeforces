#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int dp[500011];

void sep(const VI &v, VI &a, VI &b) {
    a.clear();
    b.clear();
    int sum = 0;
    EACH (e, v) sum += *e;
    if (sum % 2) return;

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int high = 0;
    REP (i, v.size()) {
	for (int j=min(high, sum/2-v[i]); j>=0; j--) if (dp[j] != -1 && dp[j+v[i]] == -1) {
	    dp[j+v[i]] = v[i];
	}
	high += v[i];
    }

    if (dp[sum/2] == -1) return;

    int cur = sum/2;
    while (cur) {
	a.push_back(dp[cur]);
	cur -= dp[cur];
    }
    sort(a.begin(), a.end());
    
    int i = 0, j = 0;
    while (i < (int)v.size()) {
	if (j < (int)a.size() && v[i] == a[j]) {
	    i++;
	    j++;
	} else {
	    b.push_back(v[i]);
	    i++;
	}
    }
}

VI HOR, VER;


vector<pair<int, int> > ans;
bool solve() {
    if (HOR.size() != VER.size()) return false;

    sort(HOR.begin(), HOR.end());
    sort(VER.begin(), VER.end());
    
    VI h1, h2;
    sep(HOR, h1, h2);
    if (h1.empty()) return false;
    if (h1.size() > h2.size()) swap(h1, h2);

    VI v1, v2;
    sep(VER, v1, v2);
    if (v1.empty()) return false;
    if (v1.size() < v2.size()) swap(v1, v2);

    ans.clear();

    int x = 0, y = 0;
    ans.emplace_back(0, 0);
    REP (i, HOR.size()) {
	int m;
	if (i < (int)h1.size()) {
	    m = h1.rbegin()[i];
	} else {
	    m = -h2.rbegin()[i - h1.size()];
	}
	x += m;
	ans.emplace_back(x, y);

	if (i < (int)v1.size()) {
	    m = v1[i];
	} else {
	    m = -v2[i - v1.size()];
	}
	y += m;
	ans.emplace_back(x, y);
    }

    assert(x == 0 && y == 0);
    return true;
}

void MAIN() {
    int H, V;
    scanf("%d", &H);
    HOR.resize(H);
    REP (i, H) scanf("%d", &HOR[i]);
    scanf("%d", &V);
    VER.resize(V);
    REP (i, V) scanf("%d", &VER[i]);

    if (solve()) {
	puts("Yes");
	REP (i, ans.size()-1u) {
	    printf("%d %d\n", ans[i].first, ans[i].second);
	}
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}