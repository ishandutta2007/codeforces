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
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n); 
		scanf("%s%s",s,t);
		rep(i,0,n)s[i]-='0',t[i]-='0';
		cnt=0;
		int op=0;
		int l=0,r=n-1;
		per(i,0,n){
			if(!op){
				if(s[r]==t[i])r--;
				else{
					if(s[l]!=t[i]){
						ans[cnt++]=i+1;
					}
					else{
						ans[cnt++]=1;
						ans[cnt++]=i+1;
					}
					op^=1;
					l++;
				}
			}
			else{
				if(s[l]!=t[i])l++;
				else{
					if(s[r]==t[i]){
						ans[cnt++]=i+1;
					}
					else{
						ans[cnt++]=1;
						ans[cnt++]=i+1;	
					}
					op^=1;
					r--;
				}
			}
		}
			printf("%d ",cnt);
			rep(i,0,cnt)printf("%d ",ans[i]);
			printf("\n");
	}
}