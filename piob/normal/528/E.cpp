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
typedef pair<K, K> PKK;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int A[3010], B[3010], C[3010];
vector<PKK> P;

PKK collide(int s, int t){
	K det = A[s] * B[t] - B[s] * A[t];
	return PKK((B[t]*C[s] - B[s]*C[t])/det, (A[s]*C[t] - A[t]*C[s])/det);
}

int ord[3010];

K key(int a){
	return atan2(B[a], -A[a]);
}

bool cmp(int a, int b){
	return key(a) > key(b);
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
		if(A[i] < 0){
			A[i] *= -1;
			B[i] *= -1;
			C[i] *= -1;
		}
		ord[i] = i;
	}
	sort(ord, ord+n, cmp);
	K p2 = (K)3/n/(n-1)/(n-2);
	K res = 0;
	FWD(_i,0,n){
		int i = ord[_i];
		PKK prv = PKK(0,0);
		FWD(_j,1,n){
			int j = ord[(_i+_j)%n];
			PKK cur = collide(i, j);
			res += p2*(prv.st * cur.nd - cur.st * prv.nd);
			prv.st += cur.st;
			prv.nd += cur.nd;
		}
	}
	cout.precision(6);
	cout << fabs(res) << endl;
	return 0;
}