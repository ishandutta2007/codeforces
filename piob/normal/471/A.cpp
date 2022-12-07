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

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

map<int, int> C;
vector<int> V;

int main(){
	FWD(i,0,6){
		int a;
		scanf("%d", &a);
		++C[a];
	}
	for(auto p : C){
		if(p.y >= 4) p.y -= 4;
		FWD(i,0,p.y) V.push_back(p.x);
	}
	if(V.size() != 2)
		printf("Alien\n");
	else if(V[0] != V[1])
		printf("Bear\n");
	else
		printf("Elephant\n");
	return 0;
}