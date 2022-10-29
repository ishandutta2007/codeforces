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
char s[5009][5009];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",s[0]);
		int p=1;
		rep(i,1,n+1){
			int pos=0;
			rep(j,i,n+1)s[i][pos++]=s[0][j-1];
			if((n-i+1)&1){
				pos=n-1;
				rep(j,1,i)s[i][pos--]=s[0][j-1];
			}
			else{
				rep(j,1,i)s[i][pos++]=s[0][j-1];
			}
			s[i][n]=0;
			if(strcmp(s[p],s[i])>0){
				p=i;
			}
		}
		printf("%s\n%d\n",s[p],p);
	}
}