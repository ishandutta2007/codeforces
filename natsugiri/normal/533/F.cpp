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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

vector<int>Z_Algorithm(const string&s) {
    int n=s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
	if (i > r) {
	    l = r = i;
	    while (r<n && s[r-l] == s[r]) r++;
	    z[i] = r-l; r--;
	} else {
	    int k = i-l;
	    if (z[k] < r-i+1) z[i] = z[k];
	    else {
		l = i;
		while (r<n && s[r-l] == s[r]) r++;
		z[i] = r-l; r--;
	    }
	}
    }
    return z;
}
char buf[200011];

int B[200011][26];
char C[200011][26];
bool T_h[26];

int main() {
    scanf("%*d%*d");
    scanf("%s", buf);
    string S(buf);
    scanf("%s", buf);
    string T(buf);
    REP (i, T.size()) T_h[T[i]-'a'] = true;
    // test
    // S = "";
    // REP (i, 200000) S += string(1, "aa"[i&1]);
    // T = "";
    // REP (i, 200000-3) T += string(1, "ab"[i&1]);
    // test
    
    int TS = T.size();
    string X(T.size() + 1 + S.size(), '$');

    REP (a, 26) REP (b, 26) {
	REP (i, T.size()) {
	    if (T[i]-'a' == a) X[i] = 'a';
	    else X[i] = 'b';
	}
	REP (i, S.size()) {
	    if (S[i]-'a' == b) X[TS+1+i] = 'a';
	    else X[TS+1+i] = 'b';
	}
	VI z = Z_Algorithm(X);
	if (!T_h[a]) {
	    REP (i, S.size()) {
		if (z[i+TS+1] == TS) {
		    B[i][a] |= 1<<b;
		}
	    }
	} else {
	    // eprintf("%c %c %s\n", a+'a', b+'a', X.c_str());
	    REP (i, S.size()) {
		if (z[i+TS+1] == TS) {
		    C[i][a] = b + 'a';
		}
	    }
	}
    }

    VI ans;
    REP (i, S.size()-T.size()+1) {
	bool ok = true;
	int cnt = 0;
	set<char> se[26];
	REP (a, 26) {
	    if (T_h[a]) {
	    	cnt++;
	    	if (!C[i][a]) {
	    	    ok = false;
	    	    break;
	    	}
		
		int b = C[i][a] - 'a';
		if (C[i][b] == a + 'a' || (C[i][b] == 0 && B[i][b] & (1<<a))) {
		    se[a].insert(b+'a');
		    se[b].insert(a+'a');
		    // cnt++;
		} else {
		    ok = false;
		    break;
		}
	    }
	}
	
	if (cnt && ok) {
	    REP (a, 26) if (se[a].size() > 1u) ok = false;
	    if (ok) ans.push_back(i+1);
	}
    }

    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) {
	printf("%d%c", ans[i], i+1==i_len? '\n': ' ');
    }
	   
    
    return 0;
}