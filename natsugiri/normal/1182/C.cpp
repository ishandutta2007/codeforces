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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
char buf[1000011];
struct Data {
    int cnt;
    char last;
    string s;

    bool operator<(const Data &o) const {
	return cnt != o.cnt ? cnt < o.cnt : last < o.last;
    }
};

void MAIN() {
    scanf("%d", &N);
    vector<Data> v, w, x, y;
    REP (i, N) {
	scanf("%s", buf);
	int len = strlen(buf);
	int cnt = 0;
	char last = 0;
	REP (j, len) {
	    switch (buf[j]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		    cnt++;
		    last = buf[j];
		    break;
	    }
	}

	v.push_back((Data){ cnt, last, buf });
    }

    sort(v.begin(), v.end());
    REP (i, v.size()) {
	if (i + 1 < (int)v.size() && v[i].cnt == v[i+1].cnt && v[i].last == v[i+1].last) {
	    w.push_back(v[i]);
	    w.push_back(v[i+1]);
	    i++;
	} else {
	    x.push_back(v[i]);
	}
    }
    REP (i, x.size()) {
	if (i + 1 < (int)x.size() && x[i].cnt == x[i+1].cnt) {
	    y.push_back(x[i]);
	    y.push_back(x[i+1]);
	    i++;
	}
    }

    vector<string> ans;
    while (1) {
	if (!w.empty() && !y.empty()) {
	    REP (t, 2) {
		ans.push_back(y.back().s); y.pop_back();
		ans.push_back(w.back().s); w.pop_back();
	    }
	} else if (w.size() >= 4u) {
	    string tmp1 = w.back().s; w.pop_back();
	    string tmp2 = w.back().s; w.pop_back();
	    ans.push_back(w.back().s); w.pop_back();
	    ans.push_back(tmp1);
	    ans.push_back(w.back().s); w.pop_back();
	    ans.push_back(tmp2);
	} else {
	    break;
	}
    }

    printf("%d\n", (int)ans.size() / 4);
    REP (i, ans.size()/2u) {
	printf("%s %s\n", ans[i*2].c_str(), ans[i*2+1].c_str());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}