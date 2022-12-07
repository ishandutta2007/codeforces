#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), (a).end())
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

//int dx[] = {0,0,-1,1}; //,1,1,-1,-1}; //,0};
//int dy[] = {-1,1,0,0}; //,1,-1,1,-1}; //,0};

//inline LL gcd(LL a, LL b){ while(a&&b) a>b?a%=b:b%=a; return a+b; }

int n, ra, rb;
int s[110], a[110], b[100];
int c[110][110];
vector<PII> bst;

bool cmp(PII aa, PII bb){
	return c[aa.x][aa.y] > c[bb.x][bb.y];
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &s[i]);
		FWD(j,0,s[i]){
			scanf("%d", &c[i][j]);
			bst.push_back(PII(i,j));
		}
		a[i] = 0;
		b[i] = s[i] - 1;
	}
	sort(ALL(bst), cmp);
	bool found;
	FWD(r,0,(int)bst.size()){
		found = false;
		for(PII bs : bst){
			if(c[bs.x][bs.y] == -1) continue;
			//printf("odleglosc do %d a %d b %d\n", c[bs.x][bs.y], bs.y - a[bs.x], b[bs.x] - bs.y);
			if(bs.y - a[bs.x] == b[bs.x] - bs.y){
				if(r&1){
					rb += c[bs.x][b[bs.x]];
					c[bs.x][b[bs.x]] = -1;
					--b[bs.x];
				}else{
					ra += c[bs.x][a[bs.x]];
					c[bs.x][a[bs.x]] = -1;
					++a[bs.x];
				}
				found = true;
				break;
			}
		}
		if(!found){
			for(PII bs : bst){
				if(c[bs.x][bs.y] == -1) continue;
				if(r&1){
					rb += c[bs.x][b[bs.x]];
					c[bs.x][b[bs.x]] = -1;
					--b[bs.x];
				}else{
					ra += c[bs.x][a[bs.x]];
					c[bs.x][a[bs.x]] = -1;
					++a[bs.x];
				}
				break;
			}
		}
	}
	printf("%d %d\n", ra, rb);
	return 0;
}