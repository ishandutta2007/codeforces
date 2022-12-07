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

char buff[12];

struct cmd {
	int p, m;
	void read(){
		scanf("%s", buff);
		int n = strlen(buff);
		p = m = 0;
		FWD(i,0,n){
			if(buff[i] == '+') ++p;
			if(buff[i] == '-') --p;
			if(buff[i] == '?') ++m;
		}
	}
} A, B;

int bin(int n, int k){
	if(k == 0 || k == n) return 1;
	return bin(n-1,k) + bin(n-1,k-1);
}

int main(){
	A.read();
	B.read();
	int n = B.m;
	int k = abs(A.p-B.p);
	if(n<k || ((n-k)&1)){
		printf("0\n");
		return 0;
	}
	k = (n-k)/2;
	K res = bin(n, k);
	FWD(i,0,n) res /= 2;
	cout.precision(10);
	cout << fixed << res << endl;
	return 0;
}