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
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=500+9;
const ll mod=998244353;
int a[N][N];
int main(){
	int k;
	scanf("%d",&k);
	a[0][0]=a[1][1]=(1<<18)-1;
	a[0][1]=a[1][2]=a[2][1]=a[2][2]=k;
	a[1][0]=1<<17;
	printf("%d %d\n",3,3);
	rep(i,0,3){
		rep(j,0,3)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
}