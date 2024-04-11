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

const int MAXN = 3e5 + 5;
int a[MAXN],n;
int f[MAXN];
int stk1[MAXN],tp1,stk2[MAXN],tp2;
int fr1[MAXN],fr2[MAXN],to1[MAXN],to2[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n){
		while(tp1 > 0 && a[stk1[tp1]] > a[i]) tp1--;
		while(tp2 > 0 && a[stk2[tp2]] < a[i]) tp2--;
		fr1[i] = stk1[tp1];fr2[i] = stk2[tp2];
		stk1[++tp1] = i;stk2[++tp2] = i;
	}
	ROF(i,n,1){
		while(tp1 > 0 && a[stk1[tp1]] > a[i]) tp1--;
		while(tp2 > 0 && a[stk2[tp2]] < a[i]) tp2--;
		to1[i] = stk1[tp1];to2[i] = stk2[tp2];
		stk1[++tp1] = i;stk2[++tp2] = i;
	}
	CLR(f,0x3f);
	FOR(i,1,n){
		f[i] = std::min({f[i],f[fr1[i]]+1,f[fr2[i]]+1});
		f[1] = 0;
		f[to1[i]] = std::min(f[to1[i]],f[i]+1);
		f[to2[i]] = std::min(f[to2[i]],f[i]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}