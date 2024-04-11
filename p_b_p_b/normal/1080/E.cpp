#include<bits/stdc++.h>
#define sz 666
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int cnt[sz][sz][26];
char a[sz][sz];
int t[sz][sz];
int n,m;
#define pll pair<ll,ll>
#define MP make_pair
#define fir first
#define sec second
const ll M1=19260817,M2=998244353;
pll C (const pll &x,const pll &y){return MP((x.fir-y.fir+M1)%M1,(x.sec-y.sec+M2)%M2);}
pll H[sz][sz];
pll Hash(int *x)
{
	pll ret;
	ret.fir=ret.sec=0;
	for (int i=0;i<26;i++) (ret.fir=ret.fir*(m+1)+x[i])%=M1,(ret.sec=ret.sec*(m+1)+x[i])%=M2;
	return ret;
}
bool check(int i,int l,int r){int x=t[i][l-1]^t[i][r];return (!x)||(!(x-(x&(-x))));}
pll s[sz];
int len[sz];
ll ans;
void manacher()
{
	int mid=0,R=0;
	for (int i=1;i<=n*2;i++) if (s[i].fir>=0)
	{
		len[i]=1;
		if (R>=i) len[i]=min(len[mid*2-i],R-i+1);
		while (len[i]<i&&s[i+len[i]]==s[i-len[i]]) ++len[i];
		ans+=len[i]/2;
		if (i+len[i]-1>R) R=i+len[i]-1,mid=i;
	}
}
int main()
{
	int i,j,k;
	read>>n>>m;/*~~~*/
	for (i=1;i<=n;i++) 
	{/*~~~*/
		cin>>((a[i])+1);/*~~~*/
		for (j=1;j<=m;j++)/*~~~*/
		{/*~~~*/
			for (k=0;k<26;k++) cnt[i][j][k]=cnt[i][j-1][k];
			cnt[i][j][a[i][j]-'a']++;
			H[i][j]=Hash(cnt[i][j]);
			t[i][j]=t[i][j-1]^(1<<(a[i][j]-1));
		}/*~~~*/
	}
	for (i=1;i<=m;i++) for (j=i;j<=m;j++) 
	{/*~~~*/
		for (k=1;k<=n;k++) /*~~~*/
			s[k*2-1]=MP(0,0),s[k*2]=(check(k,i,j)?C(H[k][j],H[k][i-1]):(pll)MP(-k,-k));
		manacher();/*~~~*/
	}
	cout<<ans;
	return 0;//goodbye~
}