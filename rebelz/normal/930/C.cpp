#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int d1[100005],d2[100005],c1[100005],c2[100005],s[100005];

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=n;i++){
		x=readint(),y=readint();
		s[x]++,s[y+1]--;
	}
	for(int i=1;i<=m;i++) s[i]+=s[i-1];
	for(int i=1;i<=m;i++) c1[i]=c2[i]=1<<30;
	for(int i=1;i<=m;i++){
		d1[i]=upper_bound(c1,c1+m+1,s[i])-c1;
		chkmin(c1[d1[i]],s[i]);
	}
	for(int i=m;i>=1;i--){
		d2[i]=upper_bound(c2,c2+m+1,s[i])-c2;
		chkmin(c2[d2[i]],s[i]);
	}
	int ans=0;
	for(int i=1;i<=m;i++) chkmax(ans,d1[i]+d2[i]-1);
	printf("%d\n",ans);
	return 0;
}