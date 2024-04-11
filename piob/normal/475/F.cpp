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
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

const int INF = 1000*1000*1000;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

PII C[100010];
int res;

void dissolve(set<PII> &X, set<PII> &Y){
	if(X.size() == 1){
		++res;
		return;
	}
	set<PII>::iterator aX, bX, aY, bY, it0, it1;
	aX = X.begin();
	bX = --X.end();
	aY = Y.begin();
	bY = --Y.end();
	FWD(i,0,(int)X.size()/2){
		if(aX != X.end() && next(aX) != X.end()){
			if(aX->x + 1 < next(aX)->x){
				it0 = X.begin();
				it1 = next(aX);
				goto split;
			}
			++aX;
		}
		if(bX != X.begin()){
			if(prev(bX)->x + 1 < bX->x){
				it0 = bX;
				it1 = X.end();
				goto split;
			}
			--bX;
		}
		if(aY != Y.end() && next(aY) != Y.end()){
			if(aY->x + 1 < next(aY)->x){
				it0 = Y.begin();
				it1 = next(aY);
				goto split;
			}
			++aY;
		}
		if(bY != Y.begin()){
			if(prev(bY)->x + 1 < bY->x){
				it0 = bY;
				it1 = Y.end();
				goto split;
			}
			--bY;
		}
	}
	++res;
	return;
split:
	set<int> I;
	for(;it0!=it1;++it0)
		I.insert(it0->y);
	for(int i : I){
		X.erase(PII(C[i].x, i));
		Y.erase(PII(C[i].y, i));
	}
	dissolve(X, Y);
	X.clear();
	Y.clear();
	for(int i : I){
		X.insert(PII(C[i].x, i));
		Y.insert(PII(C[i].y, i));
	}
	dissolve(X, Y);
}

int main(){
	int n;
	scanf("%d", &n);
	set<PII> X, Y;
	FWD(i,0,n){
		scanf("%d %d", &C[i].x, &C[i].y);
		X.insert(PII(C[i].x, i));
		Y.insert(PII(C[i].y, i));
	}
	dissolve(X, Y);
	printf("%d\n", res);
	return 0;
}