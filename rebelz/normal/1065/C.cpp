#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long n,k;
long long h[200005],cnt[200005];

int main(){
	cin>>n>>k;
	long long mina=1<<30;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		cnt[h[i]]++;
		mina=min(mina,h[i]);
	}
	for(int i=200000;i>=0;i--)
		cnt[i]+=cnt[i+1];
	for(int i=200000;i>=0;i--)
		cnt[i]+=cnt[i+1];
	long long ans=0,last=0;
	for(int i=200000;i>=mina+1;i--){
		if(cnt[i]-last>k)
			ans++,last=cnt[i+1];
	}
	cout<<ans+(cnt[mina+1]!=0)<<endl;
	return 0;
}