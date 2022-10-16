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

char s[M];
int n, nep = 0;
vector < char > v;

int main(){
	scanf("%s", s);
	n = strlen(s);
	int l = 0, r = n - 1;
	for(;l < r;l += 2, r -= 2){
		if(l == r){
			v.PB(s[l]); nep = 1; break;
		}
		if(l + 1 == r){
			v.PB(s[l + 1]); nep = 1; break;
		}
		if(l + 1 == r - 1){
			v.PB(s[l + 1]); nep = 1; break;
		}
		if(s[l] == s[r] || s[l] == s[r - 1]){
			v.PB(s[l]); continue;
		}
		if(s[l + 1] == s[r] || s[l + 1] == s[r - 1]){
			v.PB(s[l + 1]); continue;
		}
	}
	for(int i = 0;i + nep < v.size();i++)
		printf("%c", v[i]);
	for(int i = v.size() - 1;i >= 0;i--)
		printf("%c", v[i]);
	printf("\n");
}