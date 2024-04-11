#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
 
#define X first
#define Y second
#define PB push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
 
const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << 18);
const int MOD = 998244353;
 
inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}
 
inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}
 
inline int mul(int A, int B){
	return (ll)A * B % MOD;
}
 
int n, p[N], bio[N], A[N], B[N], sol[N];
vector < vector < int > > cik;
vector < int > vel;
 
bool cmp(int A, int B){
	if((int)cik[A].size() == 1) return 0;
	if((int)cik[B].size() == 1) return 1;
	if((int)cik[A].size() % 2 != (int)cik[B].size() % 2)
		return (int)cik[A].size() % 2 < (int)cik[B].size() % 2;
	return (int)cik[A].size() > (int)cik[B].size();
}
 
void solve(){
	cik.clear(); vel.clear();
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i), bio[i + 1] = 0;
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		//int x = i + 1;
		p[A[i]] = x;
	}
	for(int i = 1;i <= n;i++){
		if(bio[i]) continue;
		vi tmp;
		while(!bio[i]){
			bio[i] = 1; tmp.PB(i);
			i = p[i];
		}
		vel.PB((int)cik.size());
		cik.PB(tmp);
	}
	sort(vel.begin(), vel.end(), cmp);
	int L = 1, R = n, par = 0, fir = 0;
	for(int i = 0;i < (int)vel.size();i++){
		if(!fir && (int)cik[vel[i]].size() % 2 == 1){
			fir = 1; 
			int sred = 0;
			for(int j = i;j < (int)vel.size();j++){
				sred += (int)cik[vel[j]].size() / 2;
			}
			for(int j = i;j < (int)vel.size();j++){
				sol[cik[vel[j]].back()] = L + sred + j - i;
				cik[vel[j]].pop_back();
			}
		}
		for(int j : cik[vel[i]]){
			if(par) sol[j] = R--;
			else	 sol[j] = L++;
			par = !par;
		}
	}
	ll odg = 0;
	for(int i = 1;i <= n;i++)
		odg += abs(sol[i] - sol[p[i]]);
	printf("%lld\n", odg);
	
}
 
int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}