#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 2e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BS = 31337;

struct monotone{
	deque < ll > D;
	queue < ll > Q;
	void pop(){
		if(D.front() == Q.front()) D.pop_front();
		Q.pop();
	}
	ll mx(){
		return D.front();
	}
	void add(ll x){
		Q.push(x);
		for(;!D.empty() && D.back() < x;D.pop_back());
		D.push_back(x);
	}
	void clear(){
		for(;!D.empty();) D.pop_back();
		for(;!Q.empty();) Q.pop();
	}
};

monotone M;

int n, w, a[N], m;
ll pos[N];
ll ob[N];

int main(){
	scanf("%d%d", &n, &w);
	for(int i = 0;i < n;i++){
		scanf("%d", &m);
		for(int i = 0;i < m;i++)
			scanf("%d", a + i);
		if(2 * m < w){
			ll cur = 0;
			for(int i = 0;i < m;i++){
				cur = max(cur, (ll)a[i]);
				ob[i] += cur;
			}
			cur = 0;
			for(int i = m - 1;i >= 0;i--){
				cur = max(cur, (ll)a[i]);
				ob[w - (m - i)] += cur;
			}
			pos[m] +=  cur;
			pos[w - m] -= cur;
			
		}
		else{
			int j = 0;
			if(m != w) M.add(0);
			for(int i = 0;i < w;i++){
				if(i < m) M.add(a[i]);
				if(i == m) M.add(0);
				ob[i] += M.mx();
				if(i - w + m + 1 >= 0) 
					M.pop();
			}
			M.clear();
		}
	}
	for(int i = 1;i < w;i++){
		pos[i] += pos[i - 1];
	}
	for(int i = 0;i < w;i++){
		printf("%lld ", pos[i] + ob[i]);
	}
	printf("\n");
	return 0;
}