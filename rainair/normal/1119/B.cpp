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

const int MAXN = 1000+5;
int n,h,a[MAXN];

int main(){
	scanf("%d%d",&n,&h);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n){
		std::sort(a+1,a+i+1);
		LL sm = 0;
		for(int j = i;j >= 1;j -= 2){
			sm += a[j];
		}
		if(sm > h){
			printf("%d\n",i-1);
			return 0;
		}
	}
	printf("%d\n",n);
	return 0;
}