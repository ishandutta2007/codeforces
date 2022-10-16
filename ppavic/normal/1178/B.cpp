#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);
const ld PI = 3.1415926535;
const ld EPS = 1e-9;

int cntL[M], cntR[M];

char s[M];
int n;

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 1;i < n;i++){
		cntL[i] = cntL[i - 1];
		if(s[i] == s[i - 1] && s[i - 1] == 'v')
			cntL[i]++;
	}
	for(int i = n - 2;i >= 0;i--){
		cntR[i] = cntR[i + 1];
		if(s[i] == s[i + 1] && s[i + 1] == 'v')
			cntR[i]++;
	}
	ll sol = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'o') sol += (ll)cntL[i] * cntR[i];
	}
	printf("%lld\n", sol);
	return 0;
}