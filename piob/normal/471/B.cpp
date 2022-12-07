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

int n;
int H[2010];
int O[2010];

bool cmp(int a, int b){
	return H[a] < H[b];
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &H[i]);
		O[i] = i;
	}
	sort(O, O+n, cmp);
	FWD(_i,0,n-2){
		int a = O[_i];
		int b = O[_i+1];
		int c = O[_i+2];
		if(H[a] == H[b] && H[b] == H[c]){
			printf("YES\n");
			FWD(r,0,3){
				FWD(i,0,_i) printf("%d ", O[i]+1);
				printf("%d %d %d", a+1, b+1, c+1); 
				FWD(i,_i+3,n) printf(" %d", O[i]+1);
				printf("\n");
				int d = a; a = b; b = c; c = d;
			}
			return 0;
		}
	}
	int p = -1;
	FWD(_i,0,n-1){
		int c = O[_i];
		int d = O[_i+1];
		if(H[c] == H[d]){
			if(p == -1){
				p = _i;
			}else{
				int q = _i;
				int a = O[p];
				int b = O[p+1];
				printf("YES\n");
				FWD(r,0,3){
					FWD(i,0,p) printf("%d ", O[i]+1);
					printf("%d %d ", a+1, b+1);
					FWD(i,p+2, q) printf("%d ", O[i]+1);
					printf("%d %d ", c+1, d+1);
					FWD(i,q+2,n) printf("%d ", O[i]+1);				
					printf("\n");
					if(r&1)
						swap(a, b);
					else
						swap(c, d);
				}
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}