#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef long long ll;

struct node{
	int id;
	ll p,c,ans;
	bool operator<(const node comp)const{
		return p<comp.p;
	}
}t[100005];

int n,k;
ll num[100005],maxa[100005];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i].p;
		t[i].id=i;
	}
	for(int i=1;i<=n;i++)
		cin>>t[i].c;
	sort(t+1,t+n+1);
	int x;
	for(int i=1;i<=n;i++){
		t[i].ans=t[i].c;
		x=min(i-1,k);
		for(int j=k;j>=k-x+1;j--)
			t[i].ans+=maxa[j];
		num[t[i].id]=t[i].ans;
		maxa[0]=t[i].c;
		sort(maxa,maxa+k+1);
	}
	for(int i=1;i<=n;i++)
		cout<<num[i]<<' ';
	cout<<endl;
	return 0;
}