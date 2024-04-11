#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int INF = 1000000010;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

set<PII> S;
set<PII>::iterator it;
int k;
LL sum;

struct lvl{
	int a, b, i;
	lvl(){}
	lvl(int _a, int _b, int _i) : a(_a), b(_b), i(_i) {}
};

bool cmp(lvl a, lvl b){
	return a.b < b.b;
}

int n, w;
vector<lvl> L;
int R[300010];

LL solve(){
	sort(ALL(L), cmp);
	LL res = (LL)INF*INF;
	FWD(r,0,2){
		LL cur = 0;
		S.clear();
		sum = 0;
		k = 0;
		FWD(i,0,n) S.insert(PII(L[i].a, i));
		it = S.begin();
		while(k < w && it != S.end()){
			sum += it->st;
			++k;
			++it;
		}
		if(k == w){
			res = min(res, cur+sum);
			if(r && res == cur+sum){
				while(it != S.begin()){
					--it;
					R[L[it->nd].i] = 1;
				}
				break;
			}
		}
		FWD(i,0,n){
			cur += L[i].a;
			if(it != S.end() && PII(L[i].a, i) == *it){
				sum += it->st;
				++k;	
				++it;
			}
			if(it == S.end() || PII(L[i].a, i) < *it){
				--k;
				sum -= L[i].a;
			}
			S.erase(PII(L[i].a, i));
			if(it == S.end() || PII(L[i].b-L[i].a, i) < *it){
				++k;
				sum += L[i].b-L[i].a;
			}
			S.insert(PII(L[i].b-L[i].a, i));
			while(i+k+1 < w && it != S.end()){
				sum += it->st;
				++k;
				++it;
			}
			while(i+k+1 > w && it != S.begin()){
				--k;
				--it;
				sum -= it->st;
			}
			//printf("%d/%d %lld %lld\n", i+k+1, w, cur, sum);
			if(i+k+1 == w){
				res = min(res, cur+sum);
				if(r && res == cur+sum){
					FWD(j,0,i+1) R[L[j].i] = 1;
					while(it != S.begin()){
						--it;
						++R[L[it->nd].i];
					}
					break;
				}
			}
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &w);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		L.push_back(lvl(a, b, i));
	}
	cout << solve() << endl;
	FWD(i,0,n) cout << R[i];
	cout << endl;
	return 0;
}