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

int n, d, c, last, x;
char buff[100010];

int main(){
	scanf("%s", buff);
	n = strlen(buff);
	FWD(i,0,n){
		if(buff[i] == '#'){
			buff[i] = ')';
			last = i;
			++x;
		}
		if(buff[i] == '(')
			++d;
		else if(buff[i] == ')'){
			if(d == 0){
				printf("-1\n");
				return 0;
			}
			--d;
		}
	}
	BCK(i,n-1,last){
		if(buff[i] == '('){
			if(c == 0){
				printf("-1\n");
				return 0;
			}
			--c;
		}else if(buff[i] == ')'){
			++c;
		}
	}
	FWD(i,0,x-1) printf("1\n");
	printf("%d\n", d+1);
	return 0;
}