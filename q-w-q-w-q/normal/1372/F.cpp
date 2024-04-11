#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,a[200001];
map<int,int>pos;
map<int,int>::iterator it;
inline int mn(int x,int y){
	return x<y?x:y;
}
inline int mx(int x,int y){
	return x>y?x:y;
}
inline void query(int x,int pos,int s,int &l,int &r){
	printf("? %d %d\n",pos,mn(pos+s-1,n));
	fflush(stdout);
	int t1,t2;
	scanf("%d%d",&t1,&t2);
	if(t1==x) r=pos+t2-1,l=pos-(s-t2);
	else{
		printf("? %d %d\n",mx(1,pos-s+1),pos);
		fflush(stdout);
		scanf("%d%d",&t1,&t2);
		l=pos-t2+1,r=pos+(s-t2);
	}
	for(int i=l;i<=r;i++) a[i]=x;
}
inline void solve(int l,int r){
	if(r>n) r=n;
	if(l>r) return;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int t1,t2,x,y,tp;
	scanf("%d%d",&t1,&t2);
	it=pos.upper_bound(t1),it--;
	x=t2+mx(it->second,l-1);
	while(!pos[t1]){
		printf("? %d %d\n",x,mn(x+1,n));
		fflush(stdout);
		scanf("%d%d",&y,&tp);
		pos[y]=x;
		x+=t2;
	}
	query(t1,pos[t1],t2,x,y);
	solve(l,x-1),solve(y+1,r);
}
int main(){
	cin>>n;
	pos[0]=0;
	solve(1,n);
	putchar('!');
	for(int i=1;i<=n;i++)
	printf(" %d",a[i]);
}