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
const int N=52;
const ll mod=998244353;
char s[N][5];
int ans[N];
char ss[N][5];
int main(){
	rep(i,0,26)s[i][0]=s[i+26][0]='A'+i,s[i][1]='a'+i;
	int n,k;
	scanf("%d %d",&n,&k);
	int pos=-1;
	rep(i,k,n+1){
		scanf("%s",ss[i]);
		if(ss[i][0]=='Y'&&pos==-1)pos=i; 
	}
	if(pos==-1){
		rep(i,0,n)cout<<s[ans[i]]<<' ';
		return 0;
	}
	int cnt=0;
	rep(i,0,k){
		ans[pos-i]=cnt++;
	}
	//cout<<pos<<"pos\n";
	rep(i,pos+1,n+1){
		if(ss[i][0]=='Y')ans[i]=cnt++;
		else ans[i]=ans[i-k+1];
	}
	per(i,1,pos-k+1){
		ans[i]=ans[pos-1];
	}
	rep(i,1,n+1)cout<<s[ans[i]]<<' ';
}