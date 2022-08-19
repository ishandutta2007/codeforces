#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

using namespace std;

typedef long long ll;

struct node{
	int p;
	ll c;
	bool operator<(const node comp)const{
		return c<comp.c;
	}
}k[3005];

int n,m;
ll cnt[3005],s[3005][3005],a[3005][3005],t[3005];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i].p>>k[i].c;
		a[k[i].p][++cnt[k[i].p]]=k[i].c;
	}
	for(int i=1;i<=m;i++)
		sort(a[i]+1,a[i]+cnt[i]+1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=cnt[i];j++)
			s[i][j]=s[i][j-1]+a[i][j];
	bool flag=true;
	for(int i=2;i<=m;i++)
		if(cnt[1]<=cnt[i])
			flag=false;
	if(flag){
		cout<<0<<endl;
		return 0;
	}
	sort(k+1,k+n+1);
	ll ans=0,num,mina=1ll<<60;
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		num=i-cnt[1],ans=0;
		for(int j=2;j<=m;j++)
			if(cnt[j]>=i)
				ans+=s[j][cnt[j]-i+1],num-=cnt[j]-i+1,t[j]=cnt[j]-i+1;
		for(int j=1;j<=n&&num>0;j++){
			if(k[j].p!=1&&(cnt[k[j].p]<i||(cnt[k[j].p]>=i&&t[k[j].p]<=0)))
				ans+=k[j].c,num--;
			if(cnt[k[j].p]>=i)
				t[k[j].p]--;
		}
		mina=min(mina,ans);
	}
	cout<<mina<<endl;
	return 0;
}