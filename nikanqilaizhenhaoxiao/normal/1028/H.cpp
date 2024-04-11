#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

const int maxn = 2e5 + 10, maxm = 5e6 + 1e5, maxq = 1e6 + 1e5;

int n, q, a[maxn], rem[maxm], pme[maxm], p_n, l[maxq], r[maxq], res[maxq], cnt[maxn], bipc[maxm];
vector<int> b[maxn], has[maxn];
vector<pair<int, int> > stk[maxm], ans, foo, bar, tmp;
bool isp[maxm];

template<int input_SZ, int output_SZ> struct IO {
    char s[input_SZ], t[output_SZ], *a, *b;

    IO() { fread(s, 1, input_SZ, stdin); a = s; b = t; }
    ~IO() { fwrite(t, 1, b - t, stdout); }

    char nextchar(char c) {
        return *a++;
    }

    int nextint() {
        while(*a != '-' && (*a < '0' || *a > '9')) ++a;
        bool flag = 0; int x = 0;
        if(*a == '-') ++a, flag = 1;
        while(*a >= '0' && *a <= '9') x = x * 10 + *a++ - '0';
        if(flag) x = -x;
        return x;
    }

    long long nextll() {
        while(*a != '-' && (*a < '0' || *a > '9')) ++a;
        bool flag = 0; long long x = 0;
        if(*a == '-') ++a, flag = 1;
        while(*a >= '0' && *a <= '9') x = x * 10 + *a++ - '0';
        if(flag) x = -x;
        return x;
    }

    void outchar(char c) {
        *b++ = c;
        if(b - t > output_SZ - 25) { fwrite(t, 1, b - t, stdout); b = t; }
        return;
    }

    template<typename T> void outnum(T x) {
        if(!x) { *b++ = '0'; return; }
        if(x < 0) *b++ = '-', x = -x;
        static char s[20], *a;
        a = s;
        while(x) {
            T y = x / 10;
            *a++ = x - y * 10 + '0';
            x = y;
        }
        while(a != s) *b++ = *--a;
        if(b - t > output_SZ - 25) { fwrite(t, 1, b - t, stdout); b = t; }
        return;
    }

    template<typename T> void outnum(T x, char c) {
        return outnum(x), outchar(c);
    }
};

IO<(1 << 25) | 10, (1 << 23) | 10> io;


void prepare() {
	int N = maxm - 10;
	for (int i = 2; i <= N; ++i) isp[i] = 1;
	for (int i = 2; i <= N; ++i) {
		if(isp[i]) { pme[p_n++] = i; rem[i] = i; }
		for (int j = 0; j < p_n; ++j) {
			int p = pme[j], x = p * i;
			if(x > N) break;
			isp[x] = 0;
			rem[x] = p;
			if(i % p == 0) break;
		}
	}
	return;
}

void pb(vector<pair<int, int> > &a, const pair<int, int> &b) {
	while(a.size() && a.back().second >= b.second) a.pop_back();
	if(a.size() && a.back().first == b.first) return;
	a.push_back(b);
	return;
}

int main() {
	prepare();
	n = io.nextint();
	q = io.nextint();
	for (int i = 1; i <= n; ++i) {
		int x = io.nextint();
		vector<int> y, t;
		for (int z = x; z > 1; ) {
			y.push_back(rem[z]);
			z /= rem[z];
		}
		sort(y.begin(), y.end());
		y.resize(unique(y.begin(), y.end()) - y.begin());
		a[i] = 1;
		for (int z: y) {
			int cnt = 0;
			while(x % z == 0) x /= z, cnt ^= 1;
			if(cnt) a[i] *= z, t.push_back(z);
		}
		cnt[i] = t.size();
		for (int s = 0; s < (1 << cnt[i]); ++s) {
			bipc[s] = __builtin_popcount(s);
			int r = 1;
			for (int j = 0; j < cnt[i]; ++j) if((s >> j) & 1) r *= t[j];
			b[i].push_back(r);
		}
	}
	for (int i = 1; i <= q; ++i) { l[i] = io.nextint(); r[i] = io.nextint(); has[r[i]].push_back(i); }
	for (int r = 1; r <= n; ++r) {
		foo.clear();
		int &cnt = ::cnt[r];
		for (int s = 0; s < b[r].size(); ++s) {
			int &x = b[r][s];
			if(stk[x].size()) {
				bar.clear();
				for (auto &t: stk[x]) bar.push_back(make_pair(t.first, t.second + cnt - (bipc[s] << 1)));
				if(!foo.size()) foo = bar;
				else {
					tmp.clear();
					for (int i = 0, j = 0; i < foo.size() || j < bar.size(); ) {
						if(i == foo.size() || j < bar.size() && bar[j] < foo[i]) pb(tmp, bar[j++]);
						else pb(tmp, foo[i++]);
					}
					foo = tmp;
				}
			}
			pb(stk[x], make_pair(r, cnt));
		}
#ifdef DEBUGg
		printf("r = %d\n", r);
		for (auto t: foo) printf("(%d, %d)\t", t.first, t.second); puts("");
#endif
		if(!ans.size()) ans = foo;
		else {
			tmp.clear();
			for (int i = 0, j = 0; i < foo.size() || j < ans.size(); ) {
				if(i == foo.size() || j < ans.size() && ans[j] < foo[i]) pb(tmp, ans[j++]);
				else pb(tmp, foo[i++]);
			}
			ans = tmp;
		}
#ifdef DEBUGg
		for (auto t: ans) printf("(%d, %d)\t", t.first, t.second); puts("");
#endif
		for (int i: has[r]) {
			int j = lower_bound(ans.begin(), ans.end(), make_pair(l[i], -1)) - ans.begin();
			res[i] = ans[j].second;
		}
	}
	for (int i = 1; i <= q; ++i) io.outnum(res[i], '\n');
	return 0;
}