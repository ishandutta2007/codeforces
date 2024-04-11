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
char s[200]; 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
			int flag=0,sum=0;
	scanf("%s",s);
	int n=strlen(s),ans=0;
	rep(i,0,n){
		if(s[i]=='1'){
			if(!flag)flag=1;
			else ans+=sum,sum=0;
		}
		else{
			if(flag)sum++;
		}
	}
	cout<<ans<<endl;
	}

}