#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vp;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 <<  LOG);

deque < int > d;

int en, odg[N][2], n, p[N], pot, q, mx;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		mx = max(x, mx);
		d.PB(x);
	}
	for(int i = 1;;i++){
		if(d.front() == mx) {
			pot = i; break;
		}
		int A = d.front(); d.pop_front();
		int B = d.front(); d.pop_front();
		odg[i][0] = A, odg[i][1] = B;
		//printf("%d %d\n", A, B);
		if(A < B) swap(A, B);
		d.push_front(A); d.PB(B);
	}
	//printf(" pot = %d\n ", pot);
	for(int i = 0;i < n;i++){
		p[i] = d.front(); d.pop_front();
	}
	for(int i = 0;i < q;i++){
		ll x; scanf("%lld", &x);
		if(x < pot){
			printf("%d %d\n", odg[(int)x][0], odg[(int)x][1]);
		}
		else{
			printf("%d %d\n", mx, p[((x - pot) % (n - 1) + 0) % (n - 1) + 1]);
		}
	}
	return 0;
}