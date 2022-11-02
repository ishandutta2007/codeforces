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

const int MAXN = 1e5 + 5;
char str[MAXN];
int n;
int a[MAXN];
int sm[MAXN];

int main(){
	scanf("%s",str+1);n = strlen(str+1);
	int cnt = 0,ps = -1;
	FOR(i,1,n){
		if(str[i] == '(') sm[i] = sm[i-1]+1;
		else if(str[i] == ')') sm[i] = sm[i-1]-1;
		else{
			ps = i;
			a[++cnt] = 1;
			sm[i] = sm[i-1]-1;
		}
		if(sm[i] < 0){
			puts("-1");
			exit(0);
		}
	}
	if(ps == -1 && sm[n] != 0){
		puts("-1");exit(0);
	}
	if(sm[n] == 0){
		FOR(i,1,cnt) printf("%d\n",a[i]);
		puts("");
		exit(0);
	}
	a[cnt] += sm[n];
	int t = 0;
	FOR(i,1,n){
		if(str[i] == '(') sm[i] = sm[i-1]+1;
		else if(str[i] == ')') sm[i] = sm[i-1]-1;
		else ++t,sm[i] = sm[i-1]-a[t];
		if(sm[i] < 0){
			puts("-1");
			exit(0);
		}
	}
	FOR(i,1,cnt) printf("%d\n",a[i]);
	return 0;
}