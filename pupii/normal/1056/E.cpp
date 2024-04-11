#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 306286129
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char S[100010],T[1000010];
int Base[1000010],Hash[1000010];
il int getHash(int l,int r){return 1ll*(Hash[r]-Hash[l-1]+mod)*Base[1000000-r]%mod;}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);scanf("%s",T+1);
	int n=strlen(S+1),m=strlen(T+1),cnt0=0,cnt1=0,ans=0;
	for(int i=1;i<=n;++i)(S[i]=='0')?(++cnt0):(++cnt1);
	Base[0]=1;for(int i=1;i<=1000000;++i)Base[i]=1ll*Base[i-1]*19491001%mod;
	for(int i=1;i<=m;++i)Hash[i]=(Hash[i-1]+1ll*T[i]*Base[i])%mod;
	for(int len0=1;len0*cnt0<=m;++len0){
		int len1=(m-len0*cnt0)/cnt1;
		if(!len1||len0*cnt0+len1*cnt1!=m)continue;
		int lst=1,H0=-1,H1=-1;
		for(int i=1;i<=n;++i)
			if(S[i]=='0'){
				if(~H0){if(getHash(lst,lst+len0-1)!=H0)goto GG;}
				else H0=getHash(lst,lst+len0-1);
				lst+=len0;
			}else{
				if(~H1){if(getHash(lst,lst+len1-1)!=H1)goto GG;}
				else H1=getHash(lst,lst+len1-1);
				lst+=len1;
			}
		if(H0==H1)goto GG;
		++ans;
	  GG:;
	}
	printf("%d\n",ans);
	return 0;
}