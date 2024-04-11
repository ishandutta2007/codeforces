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
char a[120],b[120],c[120];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s%s",a,b,c);
		int n=strlen(a);
		int flag=1;
		rep(i,0,n){
			if(b[i]!=c[i]&&a[i]!=c[i]){
				flag=0;
				break;
			} 
		}
		if(flag)printf("YES\n");
		else printf("NO\n"); 
	}
}