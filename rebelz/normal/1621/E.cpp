// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll x,y;
	node(ll x=0,ll y=0):x(x),y(y){}
	bool operator<(const node c)const{return (__int128)x*c.y<(__int128)y*c.x;}
	bool operator>(const node c)const{return (__int128)x*c.y>(__int128)y*c.x;}
	bool operator<=(const node c)const{return (__int128)x*c.y<=(__int128)y*c.x;}
	bool operator>=(const node c)const{return (__int128)x*c.y>=(__int128)y*c.x;}
}a[100005],b[100005],c[100005];

int n,m;
int nxt2[100005],nxt3[100005];
vector<int> vec[100005];
bool v1[100005],v2[100005],v3[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=node(readint(),1);
		for(int i=1;i<=m;i++){
			vec[i].resize(readint());
			for(int j=0;j<vec[i].size();j++) vec[i][j]=readint();
		}
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int i=1;i<=m;i++){
			ll sum=0;
			for(auto r:vec[i]) sum+=r;
			b[i]=node(sum,vec[i].size());
		}
		sort(b+1,b+m+1);
		for(int i=1;i<=m;i++) c[i]=b[i];
		reverse(b+1,b+m+1);
		for(int i=1;i<=m;i++){
			if(a[i]>=b[i]) v1[i]=1;
			else v1[i]=0;
			if(a[i]>=b[i+1]) v2[i]=1;
			else v2[i]=0;
			if(a[i]>=b[i-1]) v3[i]=1;
			else v3[i]=0;
		}
		int lf=0,rg=m+1;
		for(int i=1;i<=m;i++){
			if(v1[i]) lf=i;
			else break;
		}
		for(int i=m;i>=1;i--){
			if(v1[i]) rg=i;
			else break;
		}
		int now=m+1;
		for(int i=m;i>=1;i--){
			if(!v2[i]) now=i;
			nxt2[i]=now;
		}
		now=m+1;
		for(int i=m;i>=1;i--){
			if(!v3[i]) now=i;
			nxt3[i]=now;
		}
		nxt2[m+1]=nxt3[m+1]=m+1;
		for(int i=1;i<=m;i++){
			ll sum=0;
			for(auto r:vec[i]) sum+=r;
			for(auto r:vec[i]){
				node tmp(sum-r,vec[i].size()-1);
				int pl1=lower_bound(c+1,c+m+1,node(sum,vec[i].size()))-c;
				pl1=m-pl1+1;
				int pl2=lower_bound(c+1,c+m+1,tmp)-c;
				pl2=m-pl2+1;
//				cout<<"test "<<pl1<<' '<<pl2<<endl;
				if(pl1<=pl2){
					if(lf>=pl1-1&&rg<=pl2+1&&nxt2[pl1]>=pl2&&a[pl2]>=tmp) putchar('1');
					else putchar('0');
				}
				else{
					if(lf>=pl2&&rg<=pl1+1&&nxt3[pl2+2]>=pl1+1&&a[pl2+1]>=tmp) putchar('1');
					else putchar('0');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}