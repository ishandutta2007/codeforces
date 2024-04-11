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

const int N = 100010;

int n;
char buff[63];
string st[N], nd[N];
int p[N];

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		scanf("%s", buff);
		st[i] = buff;
		scanf("%s", buff);
		nd[i] = buff;
	}
	FWD(i,1,n+1) scanf("%d", &p[i]);
	string last = min(st[p[1]], nd[p[1]]);
	FWD(i,2,n+1){
		string a = st[p[i]];
		string b = nd[p[i]];
		if(last < min(a,b)){
			last = min(a,b);
		}else if(last < max(a, b)){
			last = max(a, b);
		}else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}