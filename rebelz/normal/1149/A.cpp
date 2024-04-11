#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
int cnt[5],pri[400005],ans[200005];
bool fl[400005];

void getprime(int g){
	fl[1]=true;
	for(int i=2;i<=g;i++){
		if(!fl[i]) pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=g;j++){
			fl[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
}

int main(){
	getprime(400000);
	n=readint();
	for(int i=1;i<=n;i++) cnt[readint()]++;
	int now=0;
	for(int i=1;i<=n;i++){
		if(cnt[1]==0){
			for(int j=i;j<=n;j++) ans[j]=2;
			break;
		}
		else if(cnt[2]==0){
			for(int j=i;j<=n;j++) ans[j]=1;
			break;
		}
		if(!fl[now+1]) cnt[1]--,ans[i]=1,now++;
		else cnt[2]--,ans[i]=2,now+=2;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}