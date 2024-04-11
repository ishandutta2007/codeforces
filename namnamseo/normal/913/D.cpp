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
int T;
struct D {
	int x, y, i;
	bool operator<(const D& r) const {
		return x<r.x;
	}
};
D d[200010];

int si[200010];
int ri[200010];

const int M = 262144;
int tcnt[M<<1];
int tsum[M<<1];

inline void Pi(int i){
	tcnt[i] = tcnt[i*2] + tcnt[i*2+1];
	tsum[i] = tsum[i*2] + tsum[i*2+1];
}

void Init(){
	for(int i=1; i<=n; ++i) si[i]=i;
	sort(si+1, si+n+1, [&](const int& a, const int& b){
		return d[a].y < d[b].y;
	});
	for(int i=1; i<=n; ++i) ri[si[i]]=i;
}

multiset<pp> TT;

void Add(int p){
	TT.emplace(d[p].y, p);
	int t = M + ri[p];
	tcnt[t]=1; tsum[t]=d[p].y; t/=2;
	while(t) Pi(t), t/=2;
}

int count_iha(){
	int p = 1, cnt = 0;
	int limit = T;
	while(p < M){
		p *= 2;
		if(tsum[p] <= limit){
			limit -= tsum[p];
			cnt += tcnt[p];
			p += 1;
		}
	}
	return cnt;
}

int main()
{
    read(n, T);
    for(int i=1; i<=n; ++i){
		int a, b; read(a, b);
		d[i] = {a, b, i};
    }
    sort(d+1, d+n+1);
    Init();
    int p = n;
    for(int SZ=n; SZ>=1; --SZ){
		while(p >= 1 && d[p].x >= SZ){
			Add(p);
			--p;
		}
		if(count_iha() >= SZ){
			printf("%d\n%d\n", SZ, SZ);
			for(;SZ--;){
				printf("%d ", d[TT.begin()->second].i);
				TT.erase(TT.begin());
			}
			return 0;
		}
    }
    puts("0\n0");
    return 0;
}