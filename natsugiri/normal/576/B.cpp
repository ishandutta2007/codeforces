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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, P[100011];
bool use[100011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i), P[i]--;

    vector<pair<int, int> > Z;
    REP (i, N) {
	int cnt = 0;
	while (!use[i]) {
	    use[i] = true;
	    cnt++;
	    i = P[i];
	}
	if (cnt) Z.push_back(make_pair(cnt, i));
    }

    sort(Z.begin(), Z.end());
    bool ok = true;
    if (Z[0].first > 2) ok = false;
    for (int i=1; i<(int)Z.size(); i++) {
	if (Z[i].first % Z[0].first != 0) ok = false;
    }

    if (ok == false) {
	puts("NO");
    } else {
	puts("YES");
	VI R;
	if (Z[0].first == 1) {
	    R.push_back(Z[0].second+1);
	} else if (Z[0].first == 2) {
	    R.push_back(Z[0].second+1);
	    R.push_back(P[Z[0].second]+1);	    
	    printf("%d %d\n", R[0], R[1]);
	}
	for (int i=1; i<(int)Z.size(); i++) {
	    int k = Z[i].second;
	    REP (c, Z[i].first) {
		printf("%d %d\n", R[c%R.size()], k+1);
		k = P[k];
	    }
	}
    }
    return 0;
}