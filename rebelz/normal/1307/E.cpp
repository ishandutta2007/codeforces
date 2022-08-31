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

const int cys=1000000007;
int n,m;
int a[5005],c1[5005],c2[5005];
vector<int> t[5005],v1[5005],v2[5005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) t[a[i]].push_back(i);
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		if(y<=t[x].size()) v1[x].push_back(t[x][y-1]),v2[x].push_back(t[x][t[x].size()-y]);
		else v1[x].push_back(1<<30),v2[x].push_back(-(1<<30));
	}
	for(int i=1;i<=n;i++) sort(v1[i].begin(),v1[i].end()),sort(v2[i].begin(),v2[i].end());
	for(int i=1;i<=n;i++) c1[i]=0,c2[i]=0;
	int ans=0; ll ansval=0;
	for(int i=0;i<=n;i++){
		int now=0; ll val=1;
		bool fl=0;
		if(i==0) fl=1;
		for(int j=1;j<=n;j++){
			if(!v1[j].size()) continue;
			while(c1[j]<v1[j].size()&&i>=v1[j][c1[j]]) c1[j]++;
			while(c2[j]<v2[j].size()&&i>=v2[j][c2[j]]) c2[j]++;
			int cnt1=c1[j],cnt2=v2[j].size()-c2[j];
			if(!cnt1&&!cnt2) continue;
			if(c1[j]>0&&v1[j][c1[j]-1]==i){
				if(!cnt2) now++;
				else if(cnt2==1&&cnt1==1) now++;
				else if(cnt2>1&&cnt1>cnt2) now+=2,val=val*cnt2%cys;
				else if(cnt2>1) now+=2,val=val*(cnt2-1)%cys;
				else if(cnt2==1) now+=2;
				fl=1;
				continue;
			}
			if(!cnt1||!cnt2) now++,val=val*(cnt1+cnt2)%cys;
			else if(cnt1==1&&cnt2==1) now++,val=mod(val<<1);
			else now+=2,val=val*min(cnt1,cnt2)%cys*(max(cnt1,cnt2)-1)%cys;
		}
		if(!fl) continue;
		if(chkmax(ans,now)) ansval=val;
		else if(ans==now) ansval=mod(ansval+val);
	}
	printf("%d %lld\n",ans,ansval);
	return 0;
}