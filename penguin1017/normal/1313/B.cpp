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
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a+b<n+1){
			printf("1 ");
			printf("%d\n",a+b-1);
		}
		else{
			if(a+b==n+1){
				if(n>1)printf("%d ",2);
				else printf("%d ",1);
			}
			else if(a+b==n+n){
				printf("%d ",n);
			}
			else{
				int tot=n-(a+b+1-n);
				printf("%d ",n-tot);
			}
			printf("%d\n",n);
		} 
	}
}