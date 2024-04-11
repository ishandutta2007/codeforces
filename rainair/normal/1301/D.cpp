#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int n,m,k;
std::vector<std::pair<int,std::string> > S;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(n == 1){
		if(k > 2*(m-1)){
			puts("NO");return 0;
		}
		if(k >= m-1){
			k -= m-1;
			S.pb(MP(m-1,"R"));
		}
		else{
			if(k) S.pb(MP(k,"R"));
			k = 0;
		}
		if(k) S.pb(MP(k,"L"));
		puts("YES");
		printf("%d\n",(int)S.size());
		for(auto x:S){
			std::cout << x.fi << " " << x.se << '\n';
		}
		return 0;
	}
	if(m == 1){
		if(k > 2*(n-1)){
			puts("NO");return 0;
		}
		if(k >= n-1){
			k -= n-1;
			S.pb(MP(n-1,"D"));
		}
		else{
			if(k) S.pb(MP(k,"D"));
			k = 0;
		}
		if(k) S.pb(MP(k,"U"));
		puts("YES");
	printf("%d\n",S.size());
	for(auto x:S){
		std::cout << x.fi << " " << x.se << '\n';
	}return 0;
}
	int t1 = (m-1)*2+2*m-1;
	int now = 1;
	if(k > 4*n*m-2*n-2*m){
		puts("NO");return 0;
	}
	while(k >= t1 && now < n){
		k -= t1;now++;
		S.pb(MP(m-1,"R"));
		S.pb(MP(m-1,"DUL"));
		S.pb(MP(1,"D"));
	}
	if(now == n && k){
		if(k >= m-1){
			k -= m-1;S.pb(MP(m-1,"R"));
		}
		else{
			if(k) S.pb(MP(k,"R"));k = 0;
		}
		if(k >= m-1){
			k -= m-1;S.pb(MP(m-1,"L"));
		}
		else{
			if(k) S.pb(MP(k,"L"));k = 0;
		}
		if(k) S.pb(MP(k,"U"));k=0;
	}
	if(k >= m-1){
		k -= m-1;S.pb(MP(m-1,"R"));
	}
	else{
		if(k) S.pb(MP(k,"R"));k = 0;
	}
	if(k >= 3*(m-1)){
		k -= 3*(m-1);
		S.pb(MP(m-1,"DUL"));
	}
	else{
		int t = k/3,q = k%3;
		k = 0;if(t) S.pb(MP(t,"DUL"));
		if(q == 1) S.pb(MP(1,"D"));
		if(q == 2) S.pb(MP(1,"DU"));
	}
	puts("YES");
	printf("%d\n",S.size());
	for(auto x:S){
		std::cout << x.fi << " " << x.se << '\n';
	}
	return 0;
}