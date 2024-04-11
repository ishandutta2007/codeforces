#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef long long ll;

int n,m,p;
int s[1000005],a[1000005],k[1000005];

int readint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int main(){
	n=readint(); m=readint(); p=readint();
	int x;
	for(int i=1;i<=m;i++){
		x=readint();
		s[x]=1;
	}
	for(int i=1;i<=p;i++)
		a[i]=readint();
	if(s[0]){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i])
			k[i]=k[i-1];
		else
			k[i]=i;
	}
	ll num=0,ans=1000000000001ll;
	for(int i=1;i<=p;i++){
		num=0;
		for(int j=0;j<n;){
			num++;
			if(j+i>n)
				break;
			if(k[j+i]<=j){
				num=1000000000001ll;
				break;
			}
			j=k[j+i];
		}
		ans=min(ans,num*a[i]);
	}
	if(ans==1000000000001ll)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}