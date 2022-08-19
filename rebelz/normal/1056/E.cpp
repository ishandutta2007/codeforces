#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int hyc=1000000009;
ll n,m,x,now,ans;
char s[100005],t[1000005];
ll p[1000005],h[1000005],len[5],d[5],cnt[5];

ll calc(ll l,ll r){return (h[r]-h[l-1]*p[r-l+1]%hyc+hyc)%hyc;}

int main(){
	scanf("%s",s+1); scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1); p[0]=1;
	for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
	for(int i=1;i<=m;i++) h[i]=(h[i-1]*29+t[i]-'a'+1)%hyc;
	for(int i=1;i<=m;i++) p[i]=p[i-1]*29%hyc;
	if(cnt[1]>cnt[0]) x=1;
	bool flag;
	for(int i=1;i<=m/cnt[x];i++){
		if(m==i*cnt[x]||(m-i*cnt[x])%cnt[x^1]) continue;
		len[x]=i,len[x^1]=(m-i*cnt[x])/cnt[x^1];
		flag=true,now=1,d[0]=d[1]=0;
		for(int j=1;j<=n;j++){
			if(!d[s[j]-'0']) d[s[j]-'0']=calc(now,now+len[s[j]-'0']-1);
			else if(d[s[j]-'0']!=calc(now,now+len[s[j]-'0']-1)) flag=false;
			now+=len[s[j]-'0'];
		}
		if(flag&&d[0]!=d[1]) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}