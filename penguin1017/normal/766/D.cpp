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
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
const int p=131;
char s1[25];
map<ll,int> id;
int fa[N<<1];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n+1){
		scanf("%s",s1);
		ll val=0;
		int len=strlen(s1);
		rep(i,0,len)val=val*p+s1[i];
		id[val]=i;
	}
	rep(i,1,2*n+1)fa[i]=i;
	rep(i,0,m){
		int t;
		scanf("%d",&t);
		scanf("%s",s1);
		ll val=0;
		int len=strlen(s1);
		rep(i,0,len)val=val*p+s1[i];
		int num1=id[val],num2;
		scanf("%s",s1);
		val=0;
		len=strlen(s1);
		rep(i,0,len)val=val*p+s1[i];
		num2=id[val];
		if(find(num1)==find(num2)||find(num1+n)==find(num2)){
			if(t==1&&find(num1)==find(num2)){
				printf("YES\n");
			}
			else if(t==2&&find(num1+n)==find(num2)){
				printf("YES\n");
			}
			else printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(t==1){
			fa[find(num1)]=num2;
			fa[find(num1+n)]=num2+n;
		}
		else{
			fa[find(num1+n)]=num2;
			fa[find(num2+n)]=num1;
		}
	}
	while(q--){
		scanf("%s",s1);
		ll val=0;
		int len=strlen(s1);
		rep(i,0,len)val=val*p+s1[i];
		int num1=id[val],num2;
		scanf("%s",s1);
		val=0;
		len=strlen(s1);
		rep(i,0,len)val=val*p+s1[i];
		num2=id[val];
		if(find(num1)==find(num2)){
			printf("%d\n",1);
		}
		else if(find(num1)==find(num2+n)){
			printf("%d\n",2);
		}
		else{
			printf("%d\n",3);
		}
	}
}