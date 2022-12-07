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

int n, t, q;
int prize[200010];
int other[200010];
int mine[200010];
K res;

K inc_val(int a){
	K curA = mine[a] + other[a];
	if(mine[a] + 1 > other[a])
		return -10000;
	return prize[a] * ((mine[a]+1) / (curA+1) - mine[a] / curA);
}

K dec_val(int a){
	K curA = mine[a] + other[a];
	if(mine[a] == 0)
		return -10000;
	return prize[a] * ((mine[a]-1) / (curA-1) - mine[a] / curA);	
}

struct compINC{
	bool operator()(int a, int b){
		return make_pair(inc_val(a), a) > make_pair(inc_val(b), b);
	}
};

struct compDEC{
	bool operator()(int a, int b){
		return make_pair(dec_val(a), a) > make_pair(dec_val(b), b);
	}
};

set<int, compINC> sinc;
set<int, compDEC> sdec;

void make_inc(int i){
	//printf("inca\n");
	sinc.erase(sinc.find(i));
	sdec.erase(sdec.find(i));
	res += inc_val(i);
	++mine[i];
	--t;
	sinc.insert(i);
	sdec.insert(i);
	//printf("incb\n");
}

void make_dec(int i){
	//printf("inca\n");
	sinc.erase(sinc.find(i));
	sdec.erase(sdec.find(i));
	res += dec_val(i);
	--mine[i];
	++t;
	sinc.insert(i);
	sdec.insert(i);
	//printf("incb\n");
}

void push_all(){
	while(t){
		int i = *sinc.begin();
		if(inc_val(i) > 0)
			make_inc(i);
		else
			break;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d %d %d", &n, &t, &q);
	FWD(i,0,n) scanf("%d", &prize[i]);
	FWD(i,0,n) scanf("%d", &other[i]);
	FWD(i,0,n){
		sinc.insert(i);
		sdec.insert(i);
	}
	//printf("go go go\n");
	cout.precision(9);
	cout << fixed;
	FWD(i,0,q){
		int typ, r;
		scanf("%d %d", &typ, &r);
		--r;

		//cout << res << endl;
		res -= prize[r] * mine[r] / (K)(mine[r] + other[r]);
		if(typ == 1){
			sinc.erase(sinc.find(r));
			sdec.erase(sdec.find(r));
			++other[r];
			sinc.insert(r);
			sdec.insert(r);
		}else{
			sinc.erase(sinc.find(r));
			sdec.erase(sdec.find(r));
			--other[r];
			if(mine[r] > other[r]){
				--mine[r];
				++t;
			}
			sinc.insert(r);
			sdec.insert(r);
		}
		res += prize[r] * mine[r] / (K)(mine[r] + other[r]);
		//cout << res << endl;

		//cout << "\t0 " << inc_val(0) << endl;
		//cout << "\t1 " << inc_val(1) << endl;
		push_all();
		for(;;){
			int u = *sinc.begin();
			int v = *sdec.begin();
			//cout << u << " " << inc_val(u) << endl;
			//cout << v << " " << dec_val(v) << endl;
			if(u != v && inc_val(u) + dec_val(v) > 0){
				make_dec(v);
				make_inc(u);
			}else
				break;
		}
		cout << res << endl;
	}
	return 0;
}