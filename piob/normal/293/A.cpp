#include <cstdlib>
#include <cstdio>
#include <cstring>
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

int n;
char A[2000010];
char B[2000010];
int T[2][2];
int F, S;

int main(){
	scanf("%d", &n);
	scanf("%s %s", A, B);
	FWD(i,0,2*n)
		++T[A[i]-'0'][B[i]-'0'];
	FWD(i,0,n){
		if(T[1][1]){
			++F;
			--T[1][1];
		}else if(T[1][0]){
			++F;
			--T[1][0];
		}else if(T[0][1]){
			--T[0][1];
		}else
			--T[0][0];

		if(T[1][1]){
			++S;
			--T[1][1];
		}else if(T[0][1]){
			++S;
			--T[0][1];
		}else if(T[1][0]){
			--T[1][0];
		}else
			--T[0][0];
	}
	if(F == S)
		printf("Draw\n");
	else if(F > S)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}