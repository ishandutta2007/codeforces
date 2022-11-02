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

const int MAXN = 1e5+5;
const int ha = 5;
char str[MAXN];
int n;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int main(){
	scanf("%s",str+1);
	int len = strlen(str+1);
	FOR(i,1,len){
		n = 10*n+str[i]-'0';
		n %= 4;
	}
	if(len == 1){
		n = str[1]-'0';
	}
	else{
		n += 4;
	}
	printf("%d\n",(qpow(1,n)+qpow(2,n)+qpow(3,n)+qpow(4,n))%5);
	return 0;
}