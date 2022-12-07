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

int n, d, fc;
int a[100010], b[100010];
int c[100010];
int ord[100010];
vector<int> B;
vector<int> C;

bool cmpOrd(int x, int y){
	return a[x] > a[y];
}

LL x;
LL getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
	cin >> n >> d >> x;
	initAB();
	fc = n;
	//FWD(i,0,n) printf("%d ", a[i]); printf("\n");
	//FWD(i,0,n) printf("%d ", b[i]); printf("\n");
	FWD(i,0,n) ord[i] = i;
	sort(ord, ord+n, cmpOrd);
	bool sw = 0;
	FWD(i,0,n) if(b[i]) B.push_back(i);
	FWD(_i,0,n){
		int i = ord[_i];
		//printf("dorzucam a[%d] = %d\n", i, a[i]);
		if(fc < B.size() && !sw){
			//printf("robie switch\n");
			sw = 1;
			FWD(i,0,n) if(c[i] == 0) C.push_back(i);
		}
		if(!sw){
			//printf("bez switcha\n");
			for(int j : B){
				//printf("moze z %d\n", j);
				if(i+j < n && !c[i+j]){
					//printf("tak, wypelniam %d\n", i+j);
					--fc;
					c[i+j] = a[i];
				}
			}
		}else{
			//printf("C: "); for(int x : C) printf("%d ", x); printf("\n");
			int _k = 0;
			while(_k < C.size()){
				int k = C[_k];
				//printf("moze pozycja %d\n", k);
				++_k;
				if(k >= i){
					int j = k-i;
					if(b[j]){
						//printf("tak\n");
						c[k] = a[i];
						--_k;
						swap(C[_k], C.back());
						C.pop_back();
					}
				}
			}
		}
	}
	FWD(i,0,n) printf("%d\n", c[i]);
	return 0;
}