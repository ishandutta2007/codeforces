#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef double K;
typedef vector<int> VI;

int n, d;
vector<int> D[1024*1024];
map<int, int> last;
map<int, int> cnt;

void add(int a, int b, int c){
	a += d;
	b += d;
	while(a < b){
		if(a&1){
			D[a].push_back(c);
			++a;
		}
		if(~b&1){
			D[b].push_back(c);
			--b;
		}
		a /= 2; b /= 2;
	}
	if(a == b) D[a].push_back(c);
}

int get(int a){
	a += d;
	while(a){
		if(!D[a].empty()) return D[a].back();
		a /= 2;
	}
	return -1;
}

vector<int> V;

void push(int a, int b){
	last.clear();
	cnt.clear();
	V.push_back(a);
	V.push_back(b);
	V.push_back(a);
	V.push_back(b);
}

int main(){
	scanf("%d", &n);
	d = 1; while(d<n) d *= 2;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		++cnt[a];
		if(cnt[a] == 4){
			push(a, a);
			continue;
		}
		if(last.find(a) == last.end()){
			last[a] = i;
		}else{
			int b = get(last[a]);
			if(b != -1)
				push(b, a);
			else
				add(last[a]+1, i-1, a);
		}
	}
	printf("%d\n", (int)V.size());
	for(int v : V) printf("%d ", v); printf("\n");
	return 0;
}