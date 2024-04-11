#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int left,right;
	int g,mina,cnt;
}t[300000];

int n,q;
int s[100005];

int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}

void buildtree(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	if(l==r){
		t[id].g=t[id].mina=s[l],t[id].cnt=1;
		return;
	}
	int mid=(l+r)/2;
	buildtree(id<<1,l,mid);
	buildtree(id<<1|1,mid+1,r);
	if(t[id<<1].mina<t[id<<1|1].mina)
		t[id].mina=t[id<<1].mina,t[id].cnt=t[id<<1].cnt;
	else if(t[id<<1|1].mina<t[id<<1].mina)
		t[id].mina=t[id<<1|1].mina,t[id].cnt=t[id<<1|1].cnt;
	else
		t[id].mina=t[id<<1].mina,t[id].cnt=t[id<<1].cnt+t[id<<1|1].cnt;
	t[id].g=gcd(t[id<<1].g,t[id<<1|1].g);
}

node query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r)
		return t[id];
	if(t[id<<1].right>=r)
		return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l)
		return query(id<<1|1,l,r);
	node ans1=query(id<<1,l,t[id<<1].right),ans2=query(id<<1|1,t[id<<1|1].left,r),ans;
	ans.g=gcd(ans1.g,ans2.g);
	if(ans1.mina<ans2.mina)
		ans.mina=ans1.mina,ans.cnt=ans1.cnt;
	else if(ans2.mina<ans1.mina)
		ans.mina=ans2.mina,ans.cnt=ans2.cnt;
	else
		ans.mina=ans1.mina,ans.cnt=ans1.cnt+ans2.cnt;
	return ans;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	buildtree(1,1,n);
	cin>>q;
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		node ans=query(1,x,y);
		if(ans.g==ans.mina)
			cout<<y-x+1-ans.cnt<<endl;
		else
			cout<<y-x+1<<endl;
	}
	return 0;
}