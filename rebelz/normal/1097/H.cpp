#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,d,m; ll l,r;
ll pw[105],a[30],dp[2][65][60][2],bs[65],pr[105],pl[105];

ll shift(ll x,int t){return (x>>t)|((x&((1ll<<t)-1))<<(m-t));}

ll getans(vector<ll> &b,ll dep,ll now){
	if(now>r) return 0;
	ll res=0;
	if(b.size()==1){
		for(int i=0;i<m;i++){
			if(b[0]&(1ll<<i)){
				if(now<=pr[dep]) res+=dp[0][dep][i][0]+dp[0][dep][i][1];
				else res+=dp[0][dep][i][0];
				if(now<=pl[dep]) res-=dp[1][dep][i][0]+dp[1][dep][i][1];
				else res-=dp[1][dep][i][0];
			}
		}
		return res;
	}
	for(int i=0;i<d;i++){
		vector<ll> nb(0);
		int tmp=i; ll mask=(1ll<<m)-1;
		for(int j=0;j<b.size();j++){
			mask&=shift(b[j],a[tmp]);
			tmp++;
			if(tmp==d){
				tmp=0;
				nb.push_back(mask);
				mask=(1ll<<m)-1;
			}
		}
		if(tmp!=0) nb.push_back(mask);
		res+=getans(nb,dep+1,now+pw[dep]*i);
	}
	return res;
}

void getdp(ll x,int t){
	int cnt=0;
	memset(bs,0,sizeof(bs));
	for(;x;x/=d) bs[cnt++]=x%d;
	cnt=60;
	dp[t][cnt][0][1]=1;
	for(int i=cnt;i>=1;i--)
		for(int j=0;j<m;j++)
			for(int c=0;c<=1;c++)
				for(int num=0;num<(c?bs[i-1]+1:d);num++)
					dp[t][i-1][(j+a[num])%m][c&(num==bs[i-1])]+=dp[t][i][j][c];
}

int main(){
	d=readint(); m=readint();
	pw[0]=1;
	for(int i=1;pw[i-1]<=(1e18+10)/d;i++) pw[i]=pw[i-1]*d;
	for(int i=1;i<=100;i++) if(!pw[i]) pw[i]=1e18+10;
	for(int i=0;i<d;i++) a[i]=readint();
	n=readint();
	vector<ll> b(0);
	for(int i=1;i<=n;i++) b.push_back((1ll<<(readint()+1))-1);
	l=readint()-2; r=readint()-n;
	for(int i=0;i<=100;i++) pr[i]=r%pw[i];
	for(int i=0;i<=100;i++) pl[i]=l%pw[i];
	getdp(r,0); if(l>=0) getdp(l,1);
	printf("%lld\n",getans(b,0,0));
	return 0;
}