#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct node{
	int left,right,lazy;
	int cnt[30];
}t[300000];

int n,m;
char s[100005];

void buildtree(int id,int l,int r){
	t[id].left=l,t[id].right=r,t[id].lazy=0;
	if(l==r){
		t[id].cnt[s[l]-'a'+1]=1;
		return;
	}
	int mid=(l+r)/2;
	buildtree(id<<1,l,mid);
	buildtree(id<<1|1,mid+1,r);
	for(int i=1;i<=26;i++)
		t[id].cnt[i]=t[id<<1].cnt[i]+t[id<<1|1].cnt[i];
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy=t[id<<1|1].lazy=t[id].lazy;
		memset(t[id].cnt,0,sizeof(t[id].cnt));
		t[id].cnt[t[id].lazy]=t[id].right-t[id].left+1;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int c){
	if(l>r)
		return;
	if(t[id].left==l&&t[id].right==r){
		t[id].lazy=c;
		return;
	}
	pushdown(id);
	if(t[id<<1].right>=r)
		change(id<<1,l,r,c);
	else if(t[id<<1|1].left<=l)
		change(id<<1|1,l,r,c);
	else{
		change(id<<1,l,t[id<<1].right,c);
		change(id<<1|1,t[id<<1|1].left,r,c);
	}
	for(int i=1;i<=26;i++){
		t[id].cnt[i]=0;
		if(t[id<<1].lazy)
			t[id].cnt[i]+=t[id<<1].lazy==i?t[id<<1].right-t[id<<1].left+1:0;
		else
			t[id].cnt[i]+=t[id<<1].cnt[i];
		if(t[id<<1|1].lazy)
			t[id].cnt[i]+=t[id<<1|1].lazy==i?t[id<<1|1].right-t[id<<1|1].left+1:0;
		else
			t[id].cnt[i]+=t[id<<1|1].cnt[i];
	}
}

node query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r){
		if(t[id].lazy){
			memset(t[id].cnt,0,sizeof(t[id].cnt));
			t[id].cnt[t[id].lazy]=r-l+1;
		}
		return t[id];
	}
	pushdown(id);
	if(t[id<<1].right>=r)
		return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l)
		return query(id<<1|1,l,r);
	node ans1=query(id<<1,l,t[id<<1].right),ans2=query(id<<1|1,t[id<<1|1].left,r),ans;
	for(int i=1;i<=26;i++)
		ans.cnt[i]=ans1.cnt[i]+ans2.cnt[i];
	return ans;
}

int main(){
	scanf("%d%d%s",&n,&m,s+1);
	int tmp[30],p,opt,x,y;
	char z;
	buildtree(1,1,n);
	while(m--){
		scanf("%d%d%d",&x,&y,&opt);
		memcpy(tmp,query(1,x,y).cnt,sizeof(tmp)),p=x;
		if(opt==1){
			for(int i=1;i<=26;i++){
				change(1,p,p+tmp[i]-1,i);
				p+=tmp[i];
			}
		}
		else{
			for(int i=26;i>=1;i--){
				change(1,p,p+tmp[i]-1,i);
				p+=tmp[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		memcpy(tmp,query(1,i,i).cnt,sizeof(tmp));
		for(int j=1;j<=26;j++)
			if(tmp[j]>0)
				printf("%c",'a'+j-1);
	}
	printf("\n");
	return 0;
}