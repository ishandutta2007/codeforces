#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

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

const int N = 1e6 + 500;
const int M = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 <<  LOG);

int tour[2 * OFF], prop[2 * OFF], n, m;
int a[N], b[N];

void refresh(int i){
	if(!prop[i]) return;
	tour[i] += prop[i];
	if(i < OFF){
		prop[2 * i] += prop[i];
		prop[2 * i + 1] += prop[i];
	}
	prop[i] = 0;
}

void update(int i,int a,int b,int lo,int hi,int x){
	refresh(i);
	if(lo <= a && b <= hi){
		prop[i] += x; refresh(i);
		return;
	}
	if(a > hi || b < lo) return;
	update(2 * i, a, (a + b) / 2, lo, hi, x);
	update(2 * i + 1, (a + b + 2) / 2, b, lo, hi, x);
	tour[i] = min(tour[2 * i], tour[2 * i + 1]);
}

int query(int i){
	refresh(i);
	if(tour[i] >= 0) return -1;
	if(i >= OFF) return i - OFF;
	refresh(2 * i + 1);
	if(tour[2 * i + 1] < 0) 
		return query(2 * i + 1);
	return query(2 * i);
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++){
		scanf("%d", a + i);
		update(1, 0, OFF - 1, 0, a[i], -1);
	}
	for(int i = 0;i < m;i++){
		scanf("%d", b + i);
		update(1, 0, OFF - 1, 0, b[i], 1);
	}
	int q; scanf("%d", &q);
	for(int i = 0;i < q;i++){
		int ty, x, kol; scanf("%d%d%d", &ty, &x, &kol); x--;
		if(ty == 1){
			update(1, 0, OFF - 1, 0, a[x], 1);
			a[x] = kol;
			update(1, 0, OFF - 1, 0, a[x], -1);
		}	
		else{
			update(1, 0, OFF - 1, 0, b[x], -1);
			b[x] = kol;
			update(1, 0, OFF - 1, 0, b[x], 1);
		
		}
		printf("%d\n", query(1));
	}
	return 0;
}