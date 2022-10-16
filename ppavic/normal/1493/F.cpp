#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < ll, ll > pll;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int n, m;
vector < int > pn, pm;
map < int, int > badn, badm;

void rastavi(int x, vi &v){
	for(int i = 2;i <= x;){
		if(x % i)
			i++;
		else
			v.PB(i), x /= i;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	rastavi(n, pn), rastavi(m, pm);
	int gn = 1, gm = 1;
	for(int x : pn){
		if(badn[x]) continue;
		int ans = 1;
		if(x == 2){
			printf("? %d %d %d %d %d %d\n", (n / (2 * gn)), m, 1, 1, (n / (2 * gn)) + 1, 1);
			fflush(stdout); scanf("%d", &ans);
		}
		else{
			int h = (n / (x * gn));
			printf("? %d %d %d %d %d %d\n", h * (x / 2), m, 1, 1, h * (x / 2) + 1, 1);			
			fflush(stdout); int ret; scanf("%d", &ret);
			if(ret){
				if(x % 4 == 3){
					printf("? %d %d %d %d %d %d\n", h * ((x / 2 + 1) / 2), m, h * (x / 2) + 1, 1, h * (x / 2 + (x / 2 + 1) / 2) + 1, 1);			
				}
				else{
					printf("? %d %d %d %d %d %d\n", h * (x + 3) / 4, m, h * (x / 2 - 1) + 1, 1, h * (x / 2 - 1 + (x + 3) / 4) + 1, 1);							
				}
				fflush(stdout); scanf("%d", &ans);
			}
			else
				ans = 0;
		}
		if(ans)
			gn *= x;
		else
			badn[x] = 1;
	}
	
	for(int x : pm){
		if(badm[x]) continue;
		int ans = 1;
		if(x == 2){
			printf("? %d %d %d %d %d %d\n", n, (m / (2 * gm)), 1, 1, 1, (m / (2 * gm)) + 1);
			fflush(stdout); scanf("%d", &ans);
		}
		else{
			int h = (m / (x * gm));
			printf("? %d %d %d %d %d %d\n", n, h * (x / 2), 1, 1, 1, h * (x / 2) + 1);			
			fflush(stdout); int ret; scanf("%d", &ret);
			if(ret){
				if(x % 4 == 3){
					printf("? %d %d %d %d %d %d\n", n, h * ((x / 2 + 1) / 2), 1, h * (x / 2) + 1, 1, h * (x / 2 + (x / 2 + 1) / 2) + 1);			

				}
				else{
					printf("? %d %d %d %d %d %d\n", n, h * (x + 3) / 4, 1, h * (x / 2 - 1) + 1, 1, h * (x / 2 - 1 + (x + 3) / 4) + 1);							

				}
				fflush(stdout); scanf("%d", &ans);
			}
			else
				ans = 0;
		}
		if(ans)
			gm *= x;
		else
			badm[x] = 1;
	}
	
	int ansn = 0;
	for(int i = 1;i <= n;i++)
		if(gn % i == 0)
			ansn++;
	int ansm = 0;
	for(int i = 1;i <= m;i++)
		if(gm % i == 0)
			ansm++;
	printf("! %d\n", ansn * ansm);
	fflush(stdout);
	return 0;
}