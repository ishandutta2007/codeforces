#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
int n,a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",a+i);
		std::sort(a+1,a+n+1);
		// FOR(i,1,n) printf("%d ",a[i]);puts("");
		int ls=-1,rs=-1;
		FOR(i,1,n){
			if(a[i] > ls+1 && a[i] > rs+1) break;
			else if(a[i] <= ls && a[i] <= rs) continue;
			else{
				if(a[i] == ls+1) ls++;
				else if(a[i] == rs+1)rs++;
			}
		}
		printf("%d\n",ls+rs+2);
	}
	return 0;
}