#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int ans[N],cnt;
char s[N],t[N];
void sol(char *s,int n){
	rep(i,0,n)s[i]='0'+'1'-s[i];
	reverse(s,s+n);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n); 
		scanf("%s%s",s,t);
		cnt=0;
		per(i,0,n){
			if(s[i]==t[i])continue;
			if(s[0]==t[i])sol(s,1),ans[cnt++]=1;
			sol(s,i+1),ans[cnt++]=i+1;
		}
		printf("%d ",cnt);
		rep(i,0,cnt)printf("%d ",ans[i]);
		printf("\n");
	}
}