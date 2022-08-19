#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node{
	int left,right;
	int lazy,num;
}t[1000005];

int n,q;
int a[200005],mina[200005],maxa[200005],b[200005];

void buildtree(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	t[id].lazy=0;
	if(l==r){
		t[id].num=a[l];
		return;
	}
	int mid=(l+r)/2;
	buildtree(id<<1,l,mid);
	buildtree(id<<1|1,mid+1,r);
}

void change(int id,int l,int r,int c){
	if(t[id].left==l&&t[id].right==r){
		t[id].lazy=c;
		return;
	}
	if(t[id].lazy){
		t[id<<1].lazy=t[id<<1|1].lazy=t[id].lazy;
		t[id].lazy=0;
	}
	if(t[id<<1].right>=r)
		change(id<<1,l,r,c);
	else if(t[id<<1|1].left<=l)
		change(id<<1|1,l,r,c);
	else{
		change(id<<1,l,t[id<<1].right,c);
		change(id<<1|1,t[id<<1|1].left,r,c);
	}
}

int query(int id,int p){
	if(t[id].left==p&&t[id].right==p)
		return t[id].lazy?t[id].lazy:t[id].num;
	if(t[id].lazy){
		t[id<<1].lazy=t[id<<1|1].lazy=t[id].lazy;
		t[id].lazy=0;
	}
	if(p<=t[id<<1].right)
		return query(id<<1,p);
	else
		return query(id<<1|1,p);
}

int main(){
	cin>>n>>q;
	for(int i=1;i<=q;i++)
		mina[i]=1<<30,maxa[i]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mina[a[i]]=min(mina[a[i]],i),maxa[a[i]]=max(maxa[a[i]],i);
	}
	bool flag=true;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
			flag=false;
	if(flag){
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<q<<' ';
		cout<<endl;
		return 0;
	}
	buildtree(1,1,n);
	for(int i=1;i<=q;i++)
		if(mina[i]!=1<<30)
			change(1,mina[i],maxa[i],i);
	for(int i=1;i<=n;i++)
		b[i]=query(1,i);
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]&&a[i]!=0)
			flag=true;
	if(flag){
		cout<<"NO"<<endl;
		return 0;
	}
	int tmp=q;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(mina[q]==1<<30)
				b[i]=q;
			flag=true;
			break;
		}
	}
	if(!flag&&mina[q]==1<<30){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			if(i==1||b[i-1]==0)
				continue;
			b[i]=b[i-1];
		}
	}
	for(int i=n;i>=1;i--){
		if(b[i]==0){
			if(i==n||b[i+1]==0)
				continue;
			b[i]=b[i+1];
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<b[i]<<' ';
	cout<<endl;
	return 0;
}