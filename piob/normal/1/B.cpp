#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define RINT(a) scanf("%d", &a)
#define RLL(a) scanf("%lld", &a)
#define RSTR(a) scanf("%s", a)
#define RDUB(a) scanf("%lf", &a)
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
        #define debug printf
#else
        #define debug
#endif

using namespace std;

int n, a, b, p, d;
char T[100];
stack<char> V;

int main(){
	PACKS(z){
		RSTR(T);
		n = strlen(T);
		a = 0;
		b = n - 1;
		while('A' <= T[a] && T[a] <= 'Z') a++;
		while('0' <= T[b] && T[b] <= '9') b--;
		if(b+1==a){
			d=0;
			FWD(i,0,a){
				d*='Z'-'A'+1;
				d+=T[i]-'A'+1;	
			}
			printf("R%sC%d\n", T+a, d);			
		}else{
			sscanf(T, "R%dC%d", &b, &a);
			while(a) V.push('A'+((a-1)%('Z'-'A'+1))), a=(a-1)/('Z'-'A'+1);
			while(V.size()) printf("%c", V.top()), V.pop();
			printf("%d\n", b);
		}
	}
	return 0;
}