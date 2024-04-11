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

const char* R = "qwertyuiopasdfghjkl;zxcvbnm,./";

int n, d;
char buff[110];

int main(){
	scanf("%s", buff);
	d = (buff[0] == 'L' ? 1 : -1);
	scanf("%s", buff);
	n = strlen(buff);
	FWD(i,0,n){
		FWD(j,0,30) if(buff[i] == R[j]){
			buff[i] = R[j+d];
			break;
		}
	}
	printf("%s\n", buff);
	return 0;
}