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
int a[N];
int main(){
	int tot=0,n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)tot+=i>>1;
	if(m>tot){
		printf("-1");
		return 0;
	}
	rep(i,0,n){
		if(m>=(i>>1)){
			a[i]=i+1;
			m-=i>>1;
		}
		else if(m){
			a[i]=i-(m*2)+i+1;
			m=0; 
		}
		else{
			a[i]=25000000+i*5000;
		}
		printf("%d ",a[i]); 
	}
}