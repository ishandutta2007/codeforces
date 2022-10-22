//AFO countdown:26 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2e5+10;
int n,m,a[M],f[M][2],val[M][2][2],p1[M],p2[M];
vector<pair<int,int> >v[M];

int find(int x){
	int tl=1,tr=n+1,p=n+1;
	while(tl<=tr){
		int Mid=(tl+tr)>>1;
		if (a[Mid]>=x)p=Mid,tr=Mid-1;
		else tl=Mid+1;
	}return p;
}

void solve(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n+1;i++)v[i].clear();
	sort(a+1,a+1+n);a[n+1]=inf;
	for (int i=1;i<=m;i++){
		int l=read(),r=read(),x=find(l);
		if (a[x]>r)v[x].pb(mp(l,r));//,cout<<x<<' '<<l<<' '<<r<<' '<<"qwq"<<endl;
	}
	for (int i=2;i<=n;i++){
		if (v[i].size()==0)continue;
		int len=v[i].size();
		sort(v[i].begin(),v[i].end());
		p1[0]=p1[len+1]=p2[0]=p2[len+1]=0;
		for (int j=0;j<len;j++)
			p1[j+1]=v[i][j].x-a[i-1];
		for (int j=len-1;j>=0;j--)
			p2[j+1]=max(p2[j+2],a[i]-v[i][j].y);
		val[i][0][0]=val[i][0][1]=val[i][1][0]=val[i][1][1]=inf;
		for (int j=0;j<=len;j++)
			for (int w1=0;w1<=1;w1++)
				for (int w2=0;w2<=1;w2++)
					val[i][w1][w2]=min(val[i][w1][w2],(w1+1)*p1[j]+(w2+1)*p2[j+1]);
//		cout<<val[i][0][0]<<' '<<val[i][0][1]<<' '<<val[i][1][0]<<' '<<val[i][1][1]<<endl;
	}int max1=0,max2=0;
	for (int i=0;i<v[1].size();i++)
		max1=max(max1,a[1]-v[1][i].y);
	for (int i=0;i<v[n+1].size();i++)
		max2=max(max2,v[n+1][i].x-a[n]);
	f[1][0]=max1,f[1][1]=max1*2;
	for (int i=2;i<=n;i++)
		f[i][0]=min(f[i-1][0]+val[i][1][0],f[i-1][1]+val[i][0][0]),
		f[i][1]=min(f[i-1][0]+val[i][1][1],f[i-1][1]+val[i][0][1]);
//	for (int i=1;i<=n;i++)
//		cout<<f[i][0]<<'a'<<f[i][1]<<endl;
	int ans=min(f[n][0]+max2*2,f[n][1]+max2);
	cout<<ans<<endl;
}

signed main(){
	WT{solve();}
	return 0;
}
/*
1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
vp   
*/