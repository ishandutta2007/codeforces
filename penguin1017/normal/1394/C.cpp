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
#define mp make_pair
using namespace std;
const int N=3e6+9;
const ll mod=998244353;
const ll Inf=1e18;
char s[N];
pii p[N];
int n,ansx,ansy;
bool ck(int d){
	int up,dn,lf,rt,b1,b2;
	b1 = up = rt = 1e7,b2 = -1e7,dn = lf = 0;
	rep(i , 0 , n){
		int x = p[i].first,y = p[i].second;
		up = min(up,y + d);
		dn = max(dn,y - d);
		lf = max(lf,x - d);
		rt = min(rt,x + d);
		b1 = min(b1,y - x + d);
		b2 = max(b2,y - x - d); 
	}
	if(up < dn || rt < lf || b1 < b2)return false;
	if(up - lf < b2 || dn - rt > b1)return false;
//	dd(up),dd(dn),dd(lf),dd(rt),dd(b1),de(b2);
	if(b1 >= up - lf)ansx = lf,ansy = up;
	else if(b2 <= dn - rt)ansx = rt,ansy = dn;
	else {
		ansx  = rt;
		ansy  = rt + b1;
		if(ansy > up){
			ansy = up;
			ansx = up - b1;
		}
	}
//	dd(ansx),de(ansy);
	return true;
}
int main(){
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%s",s);
		int m=strlen(s),B=0,N=0;
		rep(i,0,m)if(s[i]=='B')++B;
		else ++N;
		p[i]={B,N};
	}
	int l=0,r=1e7,ANS=0;
	while(l<=r){
		int mid=l+r>>1;
		if(ck(mid)){
			ANS=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ANS);
	while(ansx--)printf("B");
	while(ansy--)printf("N");
}