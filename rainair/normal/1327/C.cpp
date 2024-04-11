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

int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	std::vector<char> ans;
	FOR(i,1,n-1) ans.pb('U');
	FOR(i,1,m-1) ans.pb('L');// at (1,1)
	FOR(i,1,n){
		if(i&1){
			FOR(j,1,m-1) ans.pb('R');
		}
		else{
			FOR(j,1,m-1) ans.pb('L');
		}
		if(i+1 <= n) ans.pb('D');
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%c",x);puts("");
	return 0;
}