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

int main(){
	int n;
	scanf("%d", &n);
	if(n < 4)
		printf("NO\n");
	else{
		printf("YES\n");
		if(n%4 == 0){
			printf("1 * 2 = 2\n");
			printf("3 * 4 = 12\n");
			printf("2 * 12 = 24\n");
		}else if(n%4 == 1){
			printf("4 * 5 = 20\n");
			printf("20 + 3 = 23\n");
			printf("23 + 2 = 25\n");
			printf("25 - 1 = 24\n");
		}else if(n%4 == 2){
			printf("3 * 4 = 12\n");
			printf("2 * 12 = 24\n");
			printf("24 + 1 = 25\n");	
			printf("25 + 5 = 30\n");	
			printf("30 - 6 = 24\n");	
		}else if(n%4 == 3){
			printf("4 * 5 = 20\n");
			printf("20 + 6 = 26\n");
			printf("26 - 7 = 19\n");
			printf("19 + 2 = 21\n");
			printf("21 + 3 = 24\n");
			printf("24 * 1 = 24\n");
		}
		FWDS(i,5+(n%4),n+1,4){
			printf("%d + %d = %d\n", i, i+3, 2*i+3);
			printf("%d + %d = %d\n", i+1, i+2, 2*i+3);
			printf("%d - %d = 0\n", 2*i+3, 2*i+3);
			printf("24 + 0 = 24\n");
		}
	}
	return 0;
}