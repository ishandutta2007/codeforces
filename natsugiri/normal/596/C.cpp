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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

#define NO (puts("NO")*0)
const int SZ = 100111;

int N;

map<pair<int, int>, int>  mp;
pair<int,int> W[SZ], ans[SZ];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	mp[make_pair(x, y)] = -1;
    }
    REP (i, N) {
	int x;
	scanf("%d", &x);
	W[i] = make_pair(x, i);
    }

    sort(W, W+N);

    for (int i=0; i<N;) {
	pair<int, int> key(0, 0);
	if (W[i].first < 0) key.first = -W[i].first;
	else key.second = W[i].first;

	int j;
	for (j=i; j<N && W[i].first==W[j].first; j++) {
	    if (mp.count(key) == 0) return NO;
	    mp[key] = W[j].second;
	    key.first++;
	    key.second++;
	}

	i = j;
    }

    EACH (e, mp) {
	if (e->second == -1) return NO;
	pair<int, int> key = e->first;
	int x = key.first, y = key.second;
	__typeof(e) it;
	
	it = mp.find(make_pair(x-1, y));
	if (x && (it == mp.end() || it->second > e->second)) return NO;
	it = mp.find(make_pair(x, y-1));
	if (y && (it == mp.end() || it->second > e->second)) return NO;

	ans[e->second] = e->first;
    }

    puts("YES");
    REP (i, N) printf("%d %d\n", ans[i].first, ans[i].second);
    
    return 0;
}