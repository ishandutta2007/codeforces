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
const int N=2e6+9;
const ll mod=998244353;
char s[N];
int ans[N],cnt;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int l=1,r=n;
	while(l<=r){
		while(s[l]==')')++l;
		while(s[r]=='(')--r;
		//cout<<l<<' '<<r<<"check\n";
		if(l<=r){
			ans[cnt++]=l;
			ans[cnt++]=r;
			++l,--r;
		}
		else break;
	}
	if(!cnt){
		printf("0");
		return 0;
	}
	printf("%d\n%d\n",1,cnt);
	sort(ans,ans+cnt);
	rep(i,0,cnt)printf("%d ",ans[i]);
}