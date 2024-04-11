#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, m, q;

vector<int> e[1010];
int el[200010], eli[200010];
int er[200010], eri[200010];

int qs[200010];
int qt[200010];
int ql[200010];
int qr[200010];
bitset<200010> qans;

bitset<1001> reach[200010];

void solve(vector<int>& queries, int L, int R){
	if(queries.empty()) return;

	if(L == R){
		for(int q:queries){
			qans[q] = ((qs[q]==el[L] && qt[q]==er[L]) || (qs[q]==er[L] && qt[q]==el[L]));
		}
		return;
	}

	int mid = (L+R)/2;
	int cl=0, cr=0;
	for(int q:queries){
		if(qr[q] <= mid) ++cl;
		else if(mid+1 <= ql[q]) ++cr;
	}

	if(cl+cr < int(queries.size())){
		for(int i=mid; L<=i; --i){
			reach[i].reset();
			reach[i].set(el[i]); reach[i].set(er[i]);
			auto& vl = e[el[i]];
			if(eli[i]+1 < int(vl.size()) && vl[eli[i]+1] <= mid){
				reach[i] |= reach[vl[eli[i]+1]];
			}
			auto& vr = e[er[i]];
			if(eri[i]+1 < int(vr.size()) && vr[eri[i]+1] <= mid){
				reach[i] |= reach[vr[eri[i]+1]];
			}
		}
		for(int i=mid+1; i<=R; ++i){
			reach[i].reset();
			reach[i].set(el[i]); reach[i].set(er[i]);
			auto& vl = e[el[i]];
			if(eli[i]-1 >= 0 && vl[eli[i]-1] > mid){
				reach[i] |= reach[vl[eli[i]-1]];
			}
			auto& vr = e[er[i]];
			if(eri[i]-1 >= 0 && vr[eri[i]-1] > mid){
				reach[i] |= reach[vr[eri[i]-1]];
			}
		}
	}

	vector<int> esal, esar;
	esal.reserve(cl); esar.reserve(cr);

	for(int q:queries){
		if(qr[q] <= mid) esal.pb(q);
		else if(mid+1 <= ql[q]) esar.pb(q);
		else {
			qans[q] = (reach[ql[q]] & reach[qr[q]]).any();
		}
	}

	solve(esal, L, mid); solve(esar, mid+1, R);
}

int main()
{
	read(n, m, q);
	for(int i=1; i<=m; ++i){
		int a, b;
		read(a, b);
		el[i] = a;
		eli[i] = e[a].size(); e[a].pb(i);
		er[i] = b;
		eri[i] = e[b].size(); e[b].pb(i);
	}

	vector<int> esa; esa.reserve(q);
	for(int i=1; i<=q; ++i){
		read(ql[i], qr[i], qs[i], qt[i]);
		{
			auto& v=e[qs[i]];
			auto it = lower_bound(all(v), ql[i]);
			if(it == v.end()) continue;
			ql[i] = *it;
		}
		{
			auto& v=e[qt[i]];
			auto it = upper_bound(all(v), qr[i])-1;
			if(it < v.begin()) continue;
			qr[i] = *it;
		}
		if(ql[i] <= qr[i]) esa.pb(i);
	}

	solve(esa, 1, m);

	for(int i=1; i<=q; ++i) puts(qans[i] ? "Yes":"No");

	return 0;
}