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

const int MAXN = 4e5 + 5;
int n,k;
char str[MAXN];

inline void Solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",str+1);
	FOR(i,1,k){
		int cnt0=0,cnt1=0,cnt2=0;
		for(int j = i;j <= n;j += k){
			if(str[j] == '0') cnt0++;
			else if(str[j] == '1') cnt1++;
			else cnt2++;
		}
		if(cnt0&&cnt1){
			puts("NO");
			return;
		}
		if(cnt0||cnt1){
			for(int j = i;j <= n;j += k){
				if(cnt0) str[j] = '0';
				else str[j] = '1';
			}
		}
	}
	int cnt0=0,cnt1=0;
	FOR(i,1,k){
		if(str[i] == '0') ++cnt0;
		if(str[i] == '1') ++cnt1;
	}
	if(cnt0 > k/2 || cnt1 > k/2){
		puts("NO");
	}
	else{
		puts("YES");
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}