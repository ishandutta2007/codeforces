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

const int MAXN = 2e6 + 5;
char a[MAXN],b[MAXN],s[MAXN],str[MAXN];
int n,m;
int fa[MAXN],fb[MAXN];
int z[MAXN];

inline void getz(char str[],int f[]){
	int len = strlen(str+1);
	z[1] = len;int l = 1,r = 1;
	FOR(i,2,len){
		if(r < i){
			l = r = i;
			while(r <= len && str[r] == str[r-l+1]) r++;
			z[i] = r-l;
			r--;
		}
		else{// [l,r] == [1,r-l+1] => [i,r] == [i-l+1,r]
			if(z[i-l+1] < r-i+1){ // 
				z[i] = z[i-l+1];
			}
			else{
				l = i;
				while(r <= len && str[r] == str[r-l+1]) ++r;
				z[i] = r-l;--r;
			}
		}
	}
	// FOR(i,1,len) printf("%d " ,z[i]);puts("");
	FOR(i,1,n) f[i] = z[i+m+1];
}

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	LL tree[MAXN];

	inline void add(int pos,int x){
		pos++;
		for(;pos < MAXN;pos += lowbit(pos)) tree[pos] += x;
	}

	inline LL query(int pos){
		pos++;
		LL res = 0;
		for(;pos;pos -= lowbit(pos)) res += tree[pos];
		return res;
	}
}bit,bit2;

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s%s",a+1,b+1,s+1);
	FOR(i,1,m) str[i] = s[i];str[m+1] = '#';
	FOR(i,1,n) str[m+1+i] = a[i];
	// printf("%s\n",str+1);
	getz(str,fa);
	FOR(i,1,n) str[m+1+i] = b[i];
	std::reverse(str+1,str+m+1);
	std::reverse(str+m+2,str+n+m+2);
	// printf("%s\n",str+1);
	getz(str,fb);
	std::reverse(fb+1,fb+n+1);
	LL res = 0;
	FOR(i,1,n) fa[i] = std::min(fa[i],m-1),fb[i] = std::min(fb[i],m-1);
	FOR(i,1,m-2) bit.add(m-1-fb[i],fb[i]),bit2.add(m-1-fb[i],1);
	FOR(i,1,n){
		// [l1,r1] [l2,r2]  r2 <= l1+m-2
		//  max{fa+fb-m,0}
		//  fa+fb-m+1 >= 0 <=> fa >= m-1-fb
		if(i+m-2 <= n) bit.add(m-1-fb[i+m-2],fb[i+m-2]),bit2.add(m-1-fb[i+m-2],1);
		int t = bit2.query(fa[i]);
		res += 1ll*(fa[i]-m+1)*t+bit.query(fa[i]);
		bit.add(m-1-fb[i],-fb[i]);bit2.add(m-1-fb[i],-1);
	}
	printf("%lld\n",res);
	return 0;
}