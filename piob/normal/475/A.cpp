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

int n;
string T[6];

int main(){
	scanf("%d", &n);
	T[0] = ("+------------------------+\n");
	T[1] = ("|#.#.#.#.#.#.#.#.#.#.#.|D|)\n");
	T[2] = ("|#.#.#.#.#.#.#.#.#.#.#.|.|\n");
	T[3] = ("|#.......................|\n");
	T[4] = ("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
	T[5] = ("+------------------------+\n");
	FWD(i,0,11){
		FWD(j,0,3+(i==0?1:0))
			if(n){
				T[1+j+(i&&j==2?1:0)][2*i+1] = 'O';
				--n;
			}
	}
	FWD(i,0,6) printf("%s", T[i].data());
	return 0;
}