#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char map[20][20];
ll dp[1<<14|1][1<<7|1][14];
ll ans[1<<14|1];
int rev[1<<14|1];
struct tri{int a,b;ll c;};
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),A=n>>1,B=n-A;
	for(int i=0;i<n;++i)scanf("%s",map[i]);
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;++i)dp[1<<i][0][i]=1;
	for(int i=1;i<1<<n;++i){
		int p;if((p=__builtin_popcount(i))>B)continue;
		for(int j=0;j<1<<p-1;++j)
			for(int k=0;k<n;++k)
				if(dp[i][j][k]){
					for(int o=0;o<n;++o)
						if(~i>>o&1)
							dp[i|(1<<o)][j|(map[k][o]-'0'<<p-1)][o]+=dp[i][j][k];
				}
	}
	for(int i=0;i<1<<B-1;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<B-2);
	if(B==1)rev[0]=0;
	for(int S=0;S<1<<n;++S){
		if(__builtin_popcount(S)!=A)continue;
		std::vector<int>va,vb;
		int SA=S,SB=((1<<n)-1)^S;
		for(int i=0;i<n;++i)if(S>>i&1)va.push_back(i);else vb.push_back(i);
		std::vector<tri>VA,VB;
		for(int a=0;a<1<<A-1;++a)
			for(int pa:va)if(dp[SA][a][pa])
					VA.push_back({a,pa,dp[SA][a][pa]});
		for(int b=0;b<1<<B-1;++b)
			for(int pb:vb)if(dp[SB][b][pb])
				VB.push_back({b,pb,dp[SB][b][pb]});
		for(auto[a,pa,da]:VA)
			for(auto[b,pb,db]:VB)
				ans[a|(map[pa][pb]-'0'<<A-1)|(rev[b]<<A)]+=da*db;
	}
	for(int i=0;i<1<<n-1;++i)printf("%lld ",ans[i]);
	return 0;
}