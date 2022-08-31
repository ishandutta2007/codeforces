#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef long long ll;

int n;
ll sum[1000005],mina[1000005],p[1000005];

int main(){
	cin>>n;
	char ch;
	for(int i=1;i<=n;i++){
		ch=getchar();
		mina[i]=0,sum[i]=0;
		while(ch!='('&&ch!=')')
			ch=getchar();
		while(ch=='('||ch==')'){
			if(ch=='(')
				sum[i]++;
			else
				sum[i]--;
			mina[i]=min(mina[i],sum[i]);
			ch=getchar();
		}
		if(mina[i]==sum[i])
			p[sum[i]+300000]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(sum[i]>=0&&mina[i]>=0)
			ans+=1ll*p[300000-sum[i]];
	cout<<ans<<endl;
	return 0;
}