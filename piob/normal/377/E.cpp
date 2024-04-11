#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <complex>
#include <cstdint>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<LL, LL>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long LL;
 
const int MAXN = 200010;

int n, k;
LL s, res;
PII F[MAXN];

struct factory {
	LL s, p, v;
};

vector<factory> st;

LL calc(LL t, factory f){
	assert(t >= f.s);
	return (t-f.s) * f.v + f.p;
}

LL when(LL c, factory f){
	return (c - f.p + f.v - 1) / f.v + f.s;
}

LL dorzuc(LL c, LL v){
	if(c == 0){
		k = 0;
		st.clear();
		st.push_back(factory({0, 0, v}));
	}else{
		while(k+1 < (int)st.size() && 
			(
				when(c, st[k+1]) < when(c, st[k])
				|| (when(c, st[k+1]) == when(c, st[k])
					&& calc(when(c, st[k]), st[k]) < calc(when(c, st[k]), st[k+1]))
			))
			++k;
		LL t = when(c, st[k]);
		factory f = {t, calc(t, st[k])-c, v};
		while(st.size() > 1){
			factory g = st[st.size()-2];
			factory h = st.back();
			LL hi = (h.s*h.v - g.s*g.v - h.p + g.p + h.v - g.v - 1) / (h.v - g.v);
			if(hi >= f.s && calc(hi, st.back()) <= calc(hi, f))
				st.pop_back();
			else
				break;
		}
		st.push_back(f);
	}
	res = min(res, when(s, st.back()));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> s;
	FWD(i,0,n)
		cin >> F[i].y >> F[i].x;
	sort(F, F+n);
	LL ss = 0;    
	res = s;
	FWD(i,0,n){
		if(F[i].y <= ss)
			continue;
		ss = F[i].y;
		dorzuc(F[i].x, F[i].y);
	}
	cout << res << endl;
	return 0;
}