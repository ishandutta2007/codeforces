#include <stdio.h>
#include <map>
#define MN 500000
typedef std::pair<int,int> pii;

using std::map;

int n;
char s[MN+5];
map<pii,int> mp;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void solve(){
	mp.clear();
	scanf("%d%s",&n,&s[1]);
	int cD=0,cK=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='D') cD++;
		else cK++;
		int g = gcd(cD,cK);
		printf("%d%c",++mp[pii(cD/g,cK/g)]," \n"[i==n]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}