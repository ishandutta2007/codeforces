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

int n, m;
LL res;
int val[300010];
int ord[300010];
int prs[300010];
int p[300010];
int q[300010];
vector<int> mod[1000010];

bool cmp(int a, int b){
	return val[a] < val[b];
}

int zlicz(int a, int b, int v){
	return (int)(lower_bound(mod[v].begin(), mod[v].end(), b) - lower_bound(mod[v].begin(), mod[v].end(), a));
}

int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &m);
	mod[0].push_back(0);
	FWD(i,0,n){
		scanf("%d", &val[i]);
		p[i] = q[i] = i;
		ord[i] = i;
		prs[i+1] = (prs[i] + val[i]) % m;
		mod[prs[i+1]].push_back(i+1);
	}
	sort(ord, ord+n, cmp);
	FWD(_i,0,n){
		int i = ord[_i];
		//printf("range [%d, %d] with max %d @ %d\n", p[i], q[i], val[i], i);
		if(i-p[i] < q[i]-i){
			//printf("left\n");
			FWD(j,p[i],i+1){
				// prs[k] == prs[j] + val[i]
				// i+1 <= k < q[i]+2
				//printf("	[%d, [%d %d)\n", j, i+1, q[i]+2);
				res += zlicz(i+1, q[i]+2, (prs[j] + val[i]) % m);
				//printf("%lld\n", res);
			}
		}else{
			//printf("right\n");
			FWD(k,i+1,q[i]+2){
				// prs[j] == prs[k] - val[i]
				// p[i] <= j < i+1
				//printf("	[%d, %d) %d)\n", p[i], i+1, k);
				res += zlicz(p[i], i+1, (prs[k] - val[i] % m + m) % m);
				//printf("%lld\n", res);
			}
		}
		if(p[i]) q[p[i]-1] = q[i];
		p[q[i]+1] = p[i];
	}
	cout << (res-n) << endl;
	return 0;
}