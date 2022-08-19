#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int sa,ea,sb,eb;
	node(int sa=0,int ea=0,int sb=0,int eb=0):sa(sa),ea(ea),sb(sb),eb(eb){}
}a[100005];

int n;
int rmqs[100005][18],rmqe[100005][18],lg2[100005];

int getmin(int l,int r){
	int k=lg2[r-l+1];
	return min(rmqe[l][k],rmqe[r-(1<<k)+1][k]);
}

int getmax(int l,int r){
	int k=lg2[r-l+1];
	return max(rmqs[l][k],rmqs[r-(1<<k)+1][k]);
}

bool cmp(node x,node y){return x.sa==y.sa?x.ea<y.ea:x.sa<y.sa;}

void solve(){
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) rmqs[i][0]=a[i].sb,rmqe[i][0]=a[i].eb;
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			rmqs[j][i]=max(rmqs[j][i-1],rmqs[j+(1<<(i-1))][i-1]);
			rmqe[j][i]=min(rmqe[j][i-1],rmqe[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		int pl=lower_bound(a+1,a+n+1,node(a[i].ea,1<<30,0,0),cmp)-a-1;
		if(i==pl) continue;
		if(getmin(i+1,pl)<a[i].sb||getmax(i+1,pl)>a[i].eb){
			printf("NO\n");
			exit(0);
		}
	}
}

int main(){
	n=readint();
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++) a[i].sa=readint(),a[i].ea=readint(),a[i].sb=readint(),a[i].eb=readint();
	solve();
	for(int i=1;i<=n;i++) swap(a[i].sa,a[i].sb),swap(a[i].ea,a[i].eb);
	solve();
	printf("YES\n");
	return 0;
}