#include <stdio.h>
#include <string.h>
#define MN 500
typedef long long ll;
const int mod = 998244353;

int n;
int ans = 0;
int f[MN+5];

struct OPT{
	int type,x;
}opt[MN+5];

void solve(int S){
	int x = opt[S].x;
	int pw = 1;
	int maxc = 0;
	memset(f,0,sizeof(f));
	f[0] = 1;
	for(int i=1;i<=n;i++){
		if(i==S) continue;
		if(opt[i].type==1){
			if(opt[i].x>x||(opt[i].x==x&&i<S)){
				pw = 2*pw%mod;
			}else{
				for(int j=maxc;j>=0;j--)
					f[j+1] = (f[j+1]+f[j])%mod;
				maxc++;
			}
		}else{
			if(i<S) f[0] = 2*f[0]%mod;
			for(int j=0;j<maxc;j++)
				f[j] = (f[j]+f[j+1])%mod;
		}
	}
	int tans = 0;
	for(int i=0;i<=maxc;i++){
		tans = (tans+f[i])%mod;
	}
	tans = (ll)tans*x%mod;
	tans = (ll)tans*pw%mod;
	ans = (ans+tans)%mod;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c=='+'){
			opt[i].type = 1;
			scanf("%d",&opt[i].x);
		}else{
			opt[i].type = 2;
		}
	}
	for(int i=1;i<=n;i++){
		if(opt[i].type==1){
			solve(i);
		}
	}
	printf("%d\n",ans);
}