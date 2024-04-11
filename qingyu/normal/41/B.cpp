#include <bits/stdc++.h>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define VAR(A,B) __typeof(B) A=B
#define FORE(I,X) for(VAR(I,(X).begin());I!=(X).end();I++)
#define F first
#define S second
#define INF 1000000007
#define PB push_back
#define MP make_pair
typedef pair<int,int> PII;
typedef long long LL;
int wyn,ile,n,najn,tab[2007];
int main(){
	scanf("%d%d",&n,&ile);
	wyn=ile;
	najn=INF;
	REP(i,n){
		scanf("%d",&tab[i]);
		wyn=max(wyn, ile%najn+ (ile/najn)*tab[i]);

		najn=min(najn,tab[i]);
	}
	printf("%d\n",wyn);
}