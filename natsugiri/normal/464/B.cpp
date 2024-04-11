#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<valarray>
using namespace std;

typedef long long LL;

typedef vector<int> VI;
typedef vector<LL> VLL;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

LL P[8][3];
valarray<LL> A[8];
LL dot(const valarray<LL>& a, const valarray<LL>& b) {
  return (a * b).sum();
}
valarray<LL> cross(const valarray<LL>& a, const valarray<LL>& b) {
    return a.cshift(+1)*b.cshift(-1) - a.cshift(-1)*b.cshift(+1);
}

LL norm(valarray<LL> a) {
    LL r = 0;
    REP (i, a.size()) r += a[i] * a[i];
    return r;
}
typedef valarray<LL> V;

VLL toVLL(V a) {
    VLL r;
    REP (i, a.size()) r.push_back(a[i]);
    return r;
}
int main() {

    REP (i, 8) {
	REP (j, 3) {
	    scanf("%lld", P[i]+j);
	}
	sort(P[i], P[i]+3);
    }

    vector<VLL> all, ans;
    REP (i, 8) all.push_back(VLL(P[i], P[i]+3));
    sort(all.begin(), all.end());

    for (int i=1; i<8; i++) {
	for (int j=1; j<8; j++) {
	    if (i==j) continue;
	    for (int k=1; k<8; k++) {
		if (k==i || k==j) continue;
		
		do {
		    do {
			do {
			    V o(P[0], 3);
			    V t1(P[i], 3);
			    V t2(P[j], 3);
			    V t3(P[k], 3);
			    V a = t1 - o;
			    V b = t2 - o;
			    V c = t3 - o;

			    if (dot(a, b) == 0 && dot(b, c) == 0 && dot(c, a) == 0 && norm(a) == norm(b) && norm(b) == norm(c) && norm(a) != 0) {
				vector<VLL> test, tmp;
				test.push_back(toVLL(o));
				test.push_back(toVLL(a+o));
				test.push_back(toVLL(b+o));
				test.push_back(toVLL(c+o));
				test.push_back(toVLL(a+b+o));
				test.push_back(toVLL(a+c+o));
				test.push_back(toVLL(b+c+o));
				test.push_back(toVLL(a+b+c+o));

				tmp = test;

				REP (k, test.size())
				    sort(test[k].begin(), test[k].end());
				sort(test.begin(), test.end());

				if (all == test) ans = tmp;
			    }
			    
			} while (next_permutation(P[k], P[k]+3));
		    } while (next_permutation(P[j], P[j]+3));
		} while (next_permutation(P[i], P[i]+3));
	    }
	}
    }
    
    if (ans.empty()) puts("NO");
    else {
	puts("YES");
	VLL A[8];
	REP (i, 8) {
	    VLL z = ans[i];
	    sort(z.begin(), z.end());
	    REP (j, 8) {
		if (A[j].empty() && z == VLL(P[j], P[j]+3)) {
		    A[j] = ans[i];
		    break;
		}
	    }
	}
		    
	REP (i, 8) {
	    REP (j, 3) {
		printf("%lld%c", A[i][j], j==2 ? '\n' : ' ');
	    }
	}
    }
    return 0;
}