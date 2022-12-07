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

int n, p;
char buff[1010];

bool gnxt(){
	BCK(i,n-1,-1){
		++buff[i];
		while((i && buff[i-1] == buff[i]) || (i>1 && buff[i-2] == buff[i]))
			++buff[i];
		if(buff[i] < 'a'+p){
			FWD(j,i+1,n){
				buff[j] = 'a';
				while(buff[j-1] == buff[j] || (j > 1 && buff[j-2] == buff[j]))
					++buff[j];
			}
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d", &n, &p);
	scanf("%s", buff);
	if(p == 1)
		printf("NO\n");
	else if(p == 2){
		if(n == 1){
			if(buff[0] == 'a')
				printf("b\n");
			else
				printf("NO\n");	
		}else{
			if(buff[0] == 'a' && buff[1] == 'b')
				printf("ba\n");
			else
				printf("NO\n");
		}
	}else{
		if(!gnxt())
			printf("NO\n");
		else
			printf("%s\n", buff);
	}
	return 0;
}