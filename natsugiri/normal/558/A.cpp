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


int N;
vector<pair<int, int> > ne, po;
int main() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x < 0) ne.push_back(make_pair(x, y));
	else po.push_back(make_pair(x, y));
    }
    sort(ne.begin(), ne.end()); reverse(ne.begin(), ne.end());
    sort(po.begin(), po.end());

    int mi = min(ne.size(), po.size());
    int ans = 0;
    REP (i, min(mi+1, (int)ne.size())) ans += ne[i].second;
    REP (i, min(mi+1, (int)po.size())) ans += po[i].second;
    printf("%d\n", ans);
    return 0;
}