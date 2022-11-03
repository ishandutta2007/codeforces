#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char s[500010],t[500010];
int nxt[500010];
int cnt0_[500010],cnt1_[500010];
int main(){
	scanf("%s",s+1),scanf("%s",t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for(int i=2;i<=m;++i){
		int p=nxt[i-1];
		while(p&&t[p+1]!=t[i])p=nxt[p];
		if(t[p+1]==t[i])++p;
		nxt[i]=p;
	}
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;++i)if(s[i]=='0')++cnt0;else ++cnt1;
#define end {while(cnt0--)putchar('0');while(cnt1--)putchar('1');exit(0);}
	for(int i=m;i;--i){
		if(t[i]=='0')++cnt0_[i];else ++cnt1_[i];
		cnt0_[i]+=cnt0_[i+1],cnt1_[i]+=cnt1_[i+1];
	}
	if(cnt0>=cnt0_[1]&&cnt1>=cnt1_[1]){
		cnt0-=cnt0_[1];
		cnt1-=cnt1_[1];
		printf("%s",t+1);
	}else end;
	for(int i=nxt[m];i;i=nxt[i]){
		while(cnt0>=cnt0_[i+1]&&cnt1>=cnt1_[i+1]){
			cnt0-=cnt0_[i+1];
			cnt1-=cnt1_[i+1];
			printf("%s",t+i+1);
		}
	}
	while(cnt0>=cnt0_[1]&&cnt1>=cnt1_[1]){
		cnt0-=cnt0_[1];
		cnt1-=cnt1_[1];
		printf("%s",t+1);
	}
	end;
	return 0;
}