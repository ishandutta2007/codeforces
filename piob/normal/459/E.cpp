#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;

int n, m, r;
int res[300010][2];
int stm[300010];
vector<pair<int, PII>> edges;

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(make_pair(c, PII(a,b)));
	}
	sort(edges.begin(), edges.end());
	FWD(i,0,m){
		int a = edges[i].y.x;
		int b = edges[i].y.y;
		int c = edges[i].x;
		if(res[b][0] < (c==stm[a]?res[a][1]:res[a][0])+1){
			if(stm[b] != c)
				res[b][1] = res[b][0];
			res[b][0] = (c==stm[a]?res[a][1]:res[a][0])+1;
			stm[b] = c;
			r = max(r, res[b][0]);
		}
	}
	printf("%d\n", r);
	return 0;
}