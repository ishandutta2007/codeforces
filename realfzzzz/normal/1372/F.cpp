#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn];
map<int,int> mp={{0,0}};
void solve(int l,int r){
	if(l>r) return;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x,y;
	x=read();
	y=read();
	for(int i=max((--mp.lower_bound(x))->second+y,l);!mp[x];i+=y){
		printf("? %d %d\n",i,i);
		fflush(stdout);
		mp[read()]=i;
		read();
	}
	int p=mp[x];
	printf("? %d %d\n",max(p-y+1,l),p);
	fflush(stdout);
	if(read()==x) p-=read()-1;
	else{
		read();
		printf("? %d %d\n",p,min(p+y-1,r));
		fflush(stdout);
		read();
		p-=y-read();
	}
	for(int i=p;i<=p+y-1;i++) a[i]=x;
	solve(l,p-1);
	solve(p+y,r);
}
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	n=read();
	solve(1,n);
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}