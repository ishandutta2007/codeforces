#include<map>
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


int N, A[100011], B[100011];

LL merge_count(vector<pair<int, int> > &P) {
    if (P.size() == 1) return 0;
    int n = P.size();
    vector<pair<int, int> > L(P.begin(), P.begin() + n/2);
    vector<pair<int, int> > R(P.begin() + n/2, P.end());
    LL ret = merge_count(L) + merge_count(R);

    int i = 0, j = 0, k = 0;
    LL s = 0;
    for (; i<(int)L.size() && j <(int)R.size(); ) {
	if (L[i].first < R[j].first) {
	    ret += s * (L[i].second - L[i].first);
	    P[k++] = L[i++];
	} else {
	    s += (R[j].second - R[j].first);
	    P[k++] = R[j++];
	}
    }
    for (;i<(int)L.size(); ) { ret += s * (L[i].second - L[i].first); P[k++] = L[i++]; }
    for (;j<(int)R.size(); ) P[k++] = R[j++];
    
    return ret;
}


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", A+i, B+i);

    
    map<int, int> mp;
    REP (i, N) {
	if (mp.count(A[i]) == 0) mp[A[i]] = A[i];
	if (mp.count(B[i]) == 0) mp[B[i]] = B[i];
	swap(mp[A[i]], mp[B[i]]);
    }
    int prev = 0;
    vector<pair<int, int> > P;
    EACH (e, mp) {
	if (prev < e->first) P.push_back(make_pair(prev, e->first));
	prev = e->first + 1;
	P.push_back(make_pair(e->second, e->second+1));
    }


    printf("%lld\n", merge_count(P));



    return 0;
}