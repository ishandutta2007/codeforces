#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int ans;
void solve(int s,int n){
//	if(s==0)system("pause");
	if(n==3){
		printf("%d %d %d %d\n",3,s+1,s+2,s+3);
		printf("%d %d %d %d\n",3,s+1,s+2,s+3);
		return;
	}
	if(n==4){
		printf("%d %d %d %d %d\n",4,s+1,s+2,s+3,s+4);
		printf("%d %d %d %d %d\n",4,s+1,s+3,s+2,s+4);
		printf("%d %d %d %d %d\n",4,s+1,s+2,s+4,s+3);
		return;
	}
	if(n==5){
		printf("%d %d %d %d %d\n",4,s+2,s+4,s+1,s+5);
		printf("%d %d %d %d %d\n",4,s+1,s+2,s+5,s+3);
		printf("%d %d %d %d\n",3,s+1,s+2,s+3);
		printf("%d %d %d %d\n",3,s+4,s+2,s+3);
		printf("%d %d %d %d\n",3,s+3,s+4,s+5);
		printf("%d %d %d %d\n",3,s+4,s+5,s+1);
		return;
	}
	if(n==6){
		printf("%d %d %d %d\n",3,s+1,s+3,s+4);
		printf("%d %d %d %d\n",3,s+2,s+4,s+5);
		printf("%d %d %d %d\n",3,s+3,s+5,s+6);
		printf("%d %d %d %d\n",3,s+4,s+6,s+1);
		printf("%d %d %d %d\n",3,s+5,s+1,s+2);
		printf("%d %d %d %d\n",3,s+6,s+2,s+3);
		printf("%d %d %d %d %d\n",4,s+1,s+3,s+4,s+6);
		printf("%d %d %d %d %d\n",4,s+2,s+4,s+5,s+1);
		printf("%d %d %d %d %d\n",4,s+3,s+5,s+6,s+2);
		return;
	}
	int l=n/2,r=n-l;
	if(l&1)++l,--r;
	for(int i=1;i<=l;i+=2){
		for(int j=1,k=0;k<r;++k,j+=2){
			int p1=j,p2=j+1;
			if(p1>r)p1-=r;
			if(p2>r)p2-=r;
			printf("%d %d %d %d %d\n",4,s+i,s+l+p1,s+i+1,s+l+p2);
		}
	}
	solve(s,l);solve(s+l,r);
}
void get(int s,int n){
	if(n==3){
		ans+=2;
		return;
	}
	if(n==4){
		ans+=3;
		return;
	}
	if(n==5){
		ans+=6;
		return;
	}
	if(n==6){
		ans+=9;
		return;
	}
	int l=n/2,r=n-l;
	if(l&1)++l,--r;
	ans+=l*r/2;
	get(s,l);get(s+l,r);
}
int main()
{
	int n;
	cin>>n;
	get(0,n);
	printf("%d\n",ans);
	solve(0,n);
}