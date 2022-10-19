#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 20010
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void print(ll x){
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
ll n,q,a[N],jmp[15][31][N],mxjmp[15][31][N],lg[N],ans[N],arr[31][N],nxtarr[31];
pair<pair<ll,ll>,ll> qry[N];
ll getmx(ll l,ll r,ll k)
{
	return max(mxjmp[lg[r-l+1]][k][l],mxjmp[lg[r-l+1]][k][r-(1<<lg[r-l+1])+1]);
}
void buildmx(ll stg)
{
	ll i,j,k;
	for(i=0;i<n;++i)
	{
		for(j=0;j<=30;++j)
		{
			mxjmp[0][j][i]=jmp[stg][j][i];
		}
	}
	for(i=1;i<15;++i)
	{
		for(j=0;j<n;++j)
		{
			for(k=0;k<=30;++k)
			{
				mxjmp[i][k][j]=max(mxjmp[i-1][k][j],(j+(1<<(i-1))<n)?mxjmp[i-1][k][j+(1<<(i-1))]:n-1);
			}
		}
	}
	return;
}
int main(){
	ll i,j,k,l,r;
	lg[1]=0;
	for(i=2;i<N;++i)
	{
		lg[i]=lg[i>>1]+1;
	}
	n=rint(),q=rint();
	for(i=0;i<n;++i)
	{
		a[i]=rint();
		for(j=0;j<=30;++j)
		{
			jmp[0][j][i]=min(n-1,i+a[i]+j);
		}
	}
	for(i=1;i<15;++i)
	{
		buildmx(i-1);
		for(j=0;j<n;++j)
		{
			for(k=0;k<=30;++k)
			{
				for(l=0;l+k<=30;++l)
				{
					jmp[i][l+k][j]=max(jmp[i][l+k][j],getmx(j,jmp[i-1][k][j],l));
				}
			}
		}
	}
	for(i=0;i<q;++i)
	{
		l=rint()-1,r=rint()-1,k=rint();
		qry[i]=make_pair(make_pair(l,r),k);
		for(j=0;j<=k;++j)
		{
			arr[j][i]=l;
		}
	}
	for(i=14;i>=0;--i)
	{
		buildmx(i);
		for(j=0;j<q;++j)
		{
			ll mxk=qry[j].S,beg=qry[j].F.F,des=qry[j].F.S;
			for(k=0;k<=mxk;++k)
			{
				nxtarr[k]=0;
			}
			for(k=0;k<=mxk;++k)
			{
				ll curp=arr[k][j];
				for(l=0;l+k<=mxk;++l)
				{
					nxtarr[k+l]=max(nxtarr[k+l],getmx(beg,curp,l));
				}
			}
			bool nd=true;
			for(k=0;k<=mxk;++k)
			{
				nd&=(nxtarr[k]<des);
			}
			if(nd)
			{
				ans[j]+=1<<i;
				for(k=0;k<=mxk;++k)
				{
					arr[k][j]=nxtarr[k];
				}
			}
		}
	}
	for(i=0;i<q;++i)
	{
		O=obuf;
		print(ans[i]+(qry[i].F.F!=qry[i].F.S)),fwrite(obuf,O-obuf,1,stdout);
		putchar('\n');
	}
	return 0;
}