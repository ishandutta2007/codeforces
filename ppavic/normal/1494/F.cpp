#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 3e3 + 50;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

vector < int > v[N], tura;
int u1[N], u2[N], bio[N], ptr[N], proso = 0, deg[N], nep, briso[N];
int n, m;

int get_next(int brd, int x){
	return u1[brd] == x ? u2[brd] : u1[brd];
}

void euler(int x){
	for(;ptr[x] < (int)v[x].size();){
		if(bio[v[x][ptr[x]]]) { ptr[x]++; continue; };
		int y = get_next(v[x][ptr[x]], x);
		bio[v[x][ptr[x]]] = 1;
		ptr[x]++; euler(y); proso++;
	}
	tura.PB(x);
}

bool probaj(int x){
	tura.clear(); 
	memset(ptr, 0, sizeof(ptr));
	memset(bio, 0, sizeof(bio));
	memset(briso, 0, sizeof(briso));
	int uk = 0;
	for(int yy : v[x]){
		int y = get_next(yy, x);
		uk += (deg[y] & 1);
	}
	if(uk == nep){
		proso = 0;
		for(int yy : v[x]){
			int y = get_next(yy, x);
			if(deg[y] & 1){
				bio[yy] = 1;
				tura.PB(x);
				tura.PB(y);
				proso++;
			}
		}
		tura.PB(-1);
		euler(x);
		if(proso == m){
			reverse(tura.begin(), tura.end());
			return 1;
		}
		for(int yyy : v[x]){
			int pos = get_next(yyy, x);
			if(deg[pos] & 1){
				tura.clear(); 
				memset(ptr, 0, sizeof(ptr));
				memset(bio, 0, sizeof(bio));
				memset(briso, 0, sizeof(briso));
				proso = 0;
				for(int yy : v[x]){
					int y = get_next(yy, x);
					if(y == pos) continue;
					if(deg[y] & 1){
						bio[yy] = 1;
						tura.PB(x);
						tura.PB(y);
						proso++;
					}
				}
				tura.PB(-1);
				euler(pos);
				if(proso == m){
					reverse(tura.begin(), tura.end());
					return 1;
				}
			}
		}
	}	
	if(uk == nep - 1 && (deg[x] & 1)){
		proso = 0;
		for(int yy : v[x]){
			int y = get_next(yy, x);
			if(deg[y] & 1){
				bio[yy] = 1;
				tura.PB(x);
				tura.PB(y);
				proso++;
			}
		}
		tura.PB(-1);
		euler(x);
		if(proso == m){
			reverse(tura.begin(), tura.end());
			return 1;
		}
		for(int yyy : v[x]){
			int pos = get_next(yyy, x);
			if(deg[pos] & 1){
				tura.clear(); 
				memset(ptr, 0, sizeof(ptr));
				memset(bio, 0, sizeof(bio));
				memset(briso, 0, sizeof(briso));
				proso = 0;
				for(int yy : v[x]){
					int y = get_next(yy, x);
					if(y == pos) continue;
					if(deg[y] & 1){
						bio[yy] = 1;
						tura.PB(x);
						tura.PB(y);
						proso++;
					}
				}
				tura.PB(-1);
				euler(pos);
				if(proso == m){
					reverse(tura.begin(), tura.end());
					return 1;
				}
			}
		}
	}	
	if(uk == nep - 2 && (deg[x] & 1)){
		proso = 0;
		for(int yy : v[x]){
			int y = get_next(yy, x);
			if(deg[y] & 1){
				briso[y] = 1;
				bio[yy] = 1;
				tura.PB(x);
				tura.PB(y);
				proso++;
			}
		}
		int poc = 0;
		for(int i = 1;i <= n;i++)
			if(!briso[i] && (deg[i] & 1))
				poc = i;
		tura.PB(-1);
		euler(poc);
		if(proso == m){
			reverse(tura.begin(), tura.end());
			return 1;
		}
	}
	if(uk == nep - 1 && !(deg[x] & 1)){
		proso = 0;
		for(int yy : v[x]){
			int y = get_next(yy, x);
			if(deg[y] & 1){
				briso[y] = 1;
				bio[yy] = 1;
				tura.PB(x);
				tura.PB(y);
				proso++;
			}
		}
		int poc = 0;
		for(int i = 1;i <= n;i++)
			if(!briso[i] && (deg[i] & 1))
				poc = i;
		tura.PB(-1);
		euler(poc);
		if(proso == m){
			reverse(tura.begin(), tura.end());
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		scanf("%d%d", u1 + i, u2 + i);
		v[u1[i]].PB(i), v[u2[i]].PB(i);
		deg[u1[i]]++, deg[u2[i]]++;
	}
	for(int i = 1;i <= n;i++)
		nep += (deg[i] & 1);
	for(int i = 1;i <= n;i++){
		if(probaj(i)){
			printf("%d\n", (int)tura.size());
			for(int x : tura)
				printf("%d ", x);
			printf("\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}