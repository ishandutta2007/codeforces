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

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

struct video{
	int a, b, i;
	video(){}
	video(int _a, int _b, int _i) : a(_a), b(_b), i(_i) {}
};

bool cmpVA(video p, video q){ return p.a < q.a; }
bool cmpVB(video p, video q){ return p.b < q.b; }

struct channel {
	int a, b, c, i;
	channel(){}
	channel(int _a, int _b, int _c, int _i) : a(_a), b(_b), c(_c), i(_i) {}
};

bool cmpCA(channel p, channel q){ return p.a < q.a; }
bool cmpCB(channel p, channel q){ return p.b < q.b; }

int n, m, d;
map<int, int> scale;
vector<video> P;
vector<channel> Q;
LL res;
int bestp, bestq;

void check(video v, channel c){
	int d = min(c.b, v.b) - max(c.a, v.a);
	if(d < 0) return;
	if((LL)d * c.c > res){
		res = (LL)d * c.c;
		bestp = v.i;
		bestq = c.i;
	}
}

PII tree[2*1024*1024+3];

void wrzuc(int x, PII y){
	x += d;
	while(x){
		tree[x] = max(tree[x], y);
		x /= 2;
	}
}

PII znajdz(int a, int b){
	PII r = PII(0, -1);
	a += d; b += d;
	while(a < b){
		if(a&1){
			r = max(r, tree[a]);
			++a;
		}
		if((b&1)==0){
			r = max(r, tree[b]);
			--b;
		}
		a /= 2;
		b /= 2;
	}
	if(a == b) r = max(r, tree[a]);
	return r;
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		P.push_back(video(a, b, i+1));
		scale[a] = 0;
		scale[b] = 0;
	}
	FWD(i,0,m){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Q.push_back(channel(a, b, c, i+1));
		scale[a] = 0;
		scale[b] = 0;
	}

	{
		d = 0;
		for(PII p : scale) scale[p.x] = d++;
		d = 1;
		while(d < SIZE(scale)) d *= 2;
		FWD(i,1,2*d) tree[i] = PII(0, -1);
	}

	int i, b;

	// video starts not later
	sort(ALL(P), cmpVA);
	sort(ALL(Q), cmpCA);
	i = 0;
	b = -1;
	for(channel q : Q){
		while(i < SIZE(P) && P[i].a <= q.a){
			if(b == -1 || P[i].b > P[b].b) b = i;
			++i;
		}
		if(b != -1) check(P[b], q);
	}

	// video ends no sooner
	sort(ALL(P), cmpVB); reverse(ALL(P));
	sort(ALL(Q), cmpCB); reverse(ALL(Q));
	i = 0;
	b = -1;
	for(channel q : Q){
		while(i < SIZE(P) && P[i].b >= q.b){
			if(b == -1 || P[i].a < P[b].a) b = i;
			++i;
		}
		if(b != -1) check(P[b], q);
	}

	// video all inside
	sort(ALL(P), cmpVB);
	sort(ALL(Q), cmpCB);
	i = 0;
	for(channel q : Q){
		while(i < SIZE(P) && P[i].b <= q.b){
			wrzuc(scale[P[i].a], PII(P[i].b - P[i].a, i));
			++i;
		}
		PII p = znajdz(scale[q.a], scale[q.b]);
		if(p.st) check(P[p.nd], q);
	}

	cout << res << endl;
	if(res) cout << bestp << " " << bestq << endl;
	return 0;
}