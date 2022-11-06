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

int n;
int a[100010];

int c[100010];
int cc[100010];

const int under = 340;
int uc[100010], ucn;
int ucc[100010];

inline void AddNum(int x){
	if(!x) return;
	if(x <= under) ++cc[x];
}
inline void RemNum(int x){
	if(!x) return;
	if(x <= under) --cc[x];
}
inline void Add(int x){ RemNum(c[x]); ++c[x]; AddNum(c[x]); }
inline void Rem(int x){ RemNum(c[x]); --c[x]; AddNum(c[x]); }

struct Query { int ql, qr, ai; } qry[100010];
const int WOW = 340;
ll ans[100010];
int q;

int asdf[under + 10];

int main()
{
	read(n); for(int i=1; i<=n; ++i) read(a[i]), ++ucc[a[i]]; read(q);
	for(int i=1; i<=100000; ++i) if(ucc[i]>under) uc[ucn++]=i;
	for(int i=1; i<=q; ++i){ int a,b; read(a,b); qry[i]={a,b,i}; }
	int cl=1, cr=1; Add(a[1]);
	sort(qry+1, qry+q+1, [&](const Query& a, const Query& b){
		int ta=a.ql/WOW, tb=b.ql/WOW;
		if(ta != tb) return ta<tb;
		return a.qr<b.qr;
	});
	for(int i=1; i<=q; ++i){
		int tl=qry[i].ql, tr=qry[i].qr;
		while(cr<tr) Add(a[++cr]); while(tl<cl) Add(a[--cl]);
		while(tr<cr) Rem(a[cr--]); while(cl<tl) Rem(a[cl++]);
		
		priority_queue<int> pq;
		ll ans = 0;
		int nokori = -1;
		for(int i=1; i<=under; ++i) asdf[i] = cc[i];
		for(int i=1; i<=under; ++i){
			int ccc = asdf[i];
			if(ccc && nokori != -1){
				--ccc;
				ans += (nokori + i);
				if(nokori+i > under) pq.push(-(nokori+i));
				else ++asdf[nokori+i];
				nokori = -1;
			}
			ans += (2ll*i) * (ccc / 2);
			if(2*i > under){
				for(int t=0; t<ccc/2; ++t) pq.push(-2*i);
			} else {
				asdf[2*i] += ccc/2;
			}
			if(ccc % 2) nokori = i;
		}
		if(nokori != -1) pq.push(-nokori);
		for(int i=0; i<ucn; ++i) if(c[uc[i]]>under) pq.push(-c[uc[i]]);
		while(pq.size()>1llu){
			int a=pq.top(); pq.pop(); int b=pq.top(); pq.pop();
			ans -= a+b;
			pq.push(a+b);
		}
		::ans[qry[i].ai] = ans;
	}
	for(int i=1; i<=q; ++i) printf("%lld\n", ans[i]);
	return 0;
}