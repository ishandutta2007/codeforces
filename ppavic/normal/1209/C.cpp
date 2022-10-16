#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < pii > vp;
typedef set < int > si;
typedef set < ll > sl;
typedef set < pii > sp;
typedef pair < ld, ld > pt;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int T, n;
char s[N];
int pnt[N];

bool check(){
	char mi = '9', mx = '0';
	for(int i = 0;i < n;i++){
		if(pnt[i]) mx = max(mx, s[i]);
		else mi = min(mi, s[i]);
	}
	if(mx > mi) return 0;
	char lst0 = '0', lst1 = '0';
	for(int i = 0;i < n;i++){
		if(pnt[i]){
			if(s[i] < lst1) return 0;
			lst1 = s[i];
		}
		else{
			if(s[i] < lst0) return 0;
			lst0 = s[i];
		}
	}
	return 1;
}

void print(){
	for(int i = 0;i < n;i++)
		printf("%d", 2 - pnt[i]);
	printf("\n");
}

void solve(){
	memset(pnt, 0, sizeof(pnt));
	scanf("%d", &n);
	scanf("%s", s);
	int L = 0;
	for(int k = 0;k < 10;k++){
		for(int j = L;j < n;j++){
			if(s[j] == '0' + k){
				L = j; pnt[j] = 1;
			}
		}
		if(check()){
			print();
			return;
		}
	}	
	printf("-\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}