#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int A[301][301],a[301][301][301],p[4],sp,ans[301],an,R,cnt,po[301][301],iv[4],num;

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}
void mns(int &x,int y) {x=(x<y?x-y+mod:x-y);}

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int main()
{
	scanf("%d",&R),sp=0;
	if (!R) return puts("1"),0;
	for (int i=0; i<4; i++) scanf("%d",&p[i]),sp+=p[i];
	sp=quickmi(sp,mod-2);
	for (int i=0; i<4; i++) p[i]=1ll*sp*p[i]%mod,iv[i]=quickmi(p[i],mod-2);
	memset(po,0,sizeof(po)),cnt=0;
	for (int i=-R,nw; i<=R; i++)
	{
		nw=floor(sqrt(R*R-i*i)+0.000000001);
		if (nw!=0) po[150+i][150-nw]=(++cnt),po[150+i][150+nw]=(++cnt);
		else po[150+i][150]=(++cnt);
	}
	memset(a,0,sizeof(a));
	for (int j=R; j>=0; j--)
	{
		int r=floor(sqrt(R*R-j*j)+0.000000001),l=-r;
		for (int i=l; i<=r; i++)
			if (po[150+i][150+j]) a[150+i][150+j][po[150+i][150+j]]=1; else
			{
				for (int k=0; k<=cnt; k++)
					a[150+i][150+j][k]=a[150+i][151+j][k];
				mns(a[150+i][150+j][0],1);
				for (int k=0; k<=cnt; k++)
					mns(a[150+i][150+j][k],1ll*a[150+i][152+j][k]*p[3]%mod),
					mns(a[150+i][150+j][k],1ll*a[149+i][151+j][k]*p[0]%mod),
					mns(a[150+i][150+j][k],1ll*a[151+i][151+j][k]*p[2]%mod);
				for (int k=0; k<=cnt; k++) a[150+i][150+j][k]=1ll*a[150+i][150+j][k]*iv[1]%mod;
			}
	}
	for (int j=-R; j<0; j++)
	{
		int r=floor(sqrt(R*R-j*j)+0.000000001),l=-r;
		for (int i=l; i<=r; i++)
			if (po[150+i][150+j]) a[150+i][150+j][po[150+i][150+j]]=1; else
			{
				for (int k=0; k<=cnt; k++)
					a[150+i][150+j][k]=a[150+i][149+j][k];
				mns(a[150+i][150+j][0],1);
				for (int k=0; k<=cnt; k++)
					mns(a[150+i][150+j][k],1ll*a[150+i][148+j][k]*p[1]%mod),
					mns(a[150+i][150+j][k],1ll*a[149+i][149+j][k]*p[0]%mod),
					mns(a[150+i][150+j][k],1ll*a[151+i][149+j][k]*p[2]%mod);
				for (int k=0; k<=cnt; k++) a[150+i][150+j][k]=1ll*a[150+i][150+j][k]*iv[3]%mod;
			}
	}
	num=0;
	for (int j=-1; j<=0; j++)
		for (int i=-R-j; i<=R+j; i++)
		{
			A[++num][0]=1;
			mns(A[num][0],a[150+i][150+j][0]);
			add(A[num][0],1ll*a[150+i][151+j][0]*p[3]%mod);
			add(A[num][0],1ll*a[150+i][149+j][0]*p[1]%mod);
			add(A[num][0],1ll*a[149+i][150+j][0]*p[0]%mod);
			add(A[num][0],1ll*a[151+i][150+j][0]*p[2]%mod);
			for (int k=1; k<=cnt; k++)
				A[num][k]=a[150+i][150+j][k],
				mns(A[num][k],1ll*a[150+i][151+j][k]*p[3]%mod),
				mns(A[num][k],1ll*a[150+i][149+j][k]*p[1]%mod),
				mns(A[num][k],1ll*a[149+i][150+j][k]*p[0]%mod),
				mns(A[num][k],1ll*a[151+i][150+j][k]*p[2]%mod);
		}
	for (int i=1; i<=cnt; i++)
	{
		int po;
		for (int j=i; j<=cnt; j++)
			if (A[j][i]) {po=j; break;}
		if (po!=i) for (int j=0; j<=cnt; j++) swap(A[po][j],A[i][j]);
		int inv=quickmi(A[i][i],mod-2);
		for (int j=0; j<=cnt; j++) A[i][j]=1ll*A[i][j]*inv%mod;
		for (int j=i+1; j<=cnt; j++)
			if (A[j][i])
			{
				int nw=A[j][i];
				for (int k=0; k<=cnt; k++) mns(A[j][k],1ll*A[i][k]*nw%mod);
			}
	}
	for (int i=cnt; i; i--)
	{
		ans[i]=A[i][0];
		for (int j=i+1; j<=cnt; j++) mns(ans[i],1ll*ans[j]*A[i][j]%mod);
	}
	an=a[150][150][0];
	for (int i=1; i<=cnt; i++) add(an,1ll*a[150][150][i]*ans[i]%mod);
	return printf("%d\n",an),0;
}