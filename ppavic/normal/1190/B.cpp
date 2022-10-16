#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
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
typedef set < int > si;
typedef long double ld;
 
const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const ld PI = 3.1415926535;
const ld EPS = 1e-9;
 
int n, a[N], odma = 0, koj = 0;
ll sm = 0;
map < int, int > mp;


 
int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", a + i);
		sm += a[i];
		mp[a[i]]++;
		if(mp[a[i]] >= 2) odma++;
		if(mp[a[i]] >= 2) koj = a[i];
	}
	if(odma >= 2 || (odma && (mp[koj - 1] || koj == 0))){
		printf("cslnb\n");
		return 0;
	}
	sort(a, a + n);
	a[0] = 0;
	for(int i = 1;i < n;i++){
		if(a[i] > a[i - 1]){
			a[i] = a[i - 1] + 1;
		}
		sm -= a[i];
	}
	//sm -= (ll)n * (ll)(n - 1) / 2LL;
	if(sm % 2 == 0) printf("cslnb\n");
	else            printf("sjfnb\n");
}