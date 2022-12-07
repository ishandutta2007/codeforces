#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

int T[1000010];
int n, p;

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	++n;
	FWD(i,0,n) T[i] = i;
	p = 1;
	while(2*p < n) p*=2;
	while(p){
		for(int i = p; i < n; i += 2*p)
			FWD(j,i,min(i+p,n))
				swap(T[j], T[j-p]);
		//FWD(i,0,n) printf("%d ", T[i]);
		//printf("\n");
		p /= 2;
	}
	LL x = 0;
	FWD(i,0,n) x += ((LL)T[i]^i);
	cout << x << endl;
	FWD(i,0,n) cout << T[i] << " ";
	cout << endl;
	return 0;
}