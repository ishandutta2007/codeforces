#include<bits/stdc++.h>
using namespace std;
int n,t[222222],ans,a[222222];
struct th{
	int a,i_a;
	friend bool operator<(th x,th y){return x.i_a<y.i_a||(x.i_a==y.i_a&&x.a<y.a);}
}s[222222];
void add(int p,int v){for(;p<=200001;p+=p&-p)t[p]=max(t[p],v);}
int ask(int p,int a=0){for(;p;p-=p&-p)a=max(a,t[p]);return a;}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=(th){a[i],i-a[i]};
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;++i)if(s[i].i_a>=0){
		int x=ask(s[i].a)+1;
		ans=max(ans,x);
		add(s[i].a+1,x);
	}cout<<ans;
}