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
int s[6][6];
int main(){
	rep(i,0,3)rep(j,0,3)s[i][j]=1;
	s[1][1]=0;
	s[0][0]=0;
	int n;
	cin>>n;
	cout<<7*(n+1)+1<<endl;
	int x=0,y=0;
	printf("%d %d\n",x,y);
	n++;
	while(n--){
		rep(i,0,3)rep(j,0,3){
			if(s[i][j])printf("%d %d\n",x+i,y+j);
		}
		x+=2,y+=2;
	} 
}