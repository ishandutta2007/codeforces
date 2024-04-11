#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, T = 300;
int n, cnt, a[N], b[N];
ll ans;
char s[N];
int main() {
	scanf("%s", s+1), n=strlen(s+1);
	for(int i=1; i<=n; ++i){
		a[i]=a[i-1]+s[i]-'0';
		if(s[i]=='1') b[++cnt]=i;
	}
	b[cnt+1]=n+1;
	for(int i=1; i<=T; ++i){
		unordered_map<int,int> f;
		for(int j=0; j<=n; ++j) ans+=f[j-a[j]*i]++;
	}
	for(int i=1, l=1; i<=n; ++i){
		while(b[l]<i) ++l;
		for(int j=l, x=1; j<=cnt && x<=n/T; ++j, ++x){
			int l=max((T+1)*x, b[j]-i+1), r=b[j+1]-i;
			r-=r%x, l+=x-(l-1)%x-1;
			if(l<=r) ans+=(r-l)/x+1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}