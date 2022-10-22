//written by a fan of emptyhope
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

const int Mod=998244353;
const int M=1e6+10;
int n,m,q,a1[M],a2[M],a3[M],a4[M],cnt,cnt2,F,F1,F3,F4;
map<pair<int,int>,int>t;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

signed main()
{
	cnt=n=read(),cnt2=m=read(),q=read();
	while(q--)
	{
		int x=read(),y=read(),opt=read();
		if (t[mp(x,y)]!=0)
		{
			int p=(y+t[mp(x,y)])&1?1:2;
			if (p==1)
			{
				a3[x]--;
				if (a3[x]==0)
				{
					if (a4[x]==0)cnt++;
					else F--;
				}
			}
			else
			{
				a4[x]--;
				if (a4[x]==0)
				{
					if (a3[x]==0)cnt++;
					else F--;
				}
			}int b=(x+t[mp(x,y)])&1?1:2;
			if (b==1)
			{
				a1[y]--;
				if (a1[y]==0)
				{
					if (a2[y]==0)cnt2++;
					else F1--;
					if (y&1)F3--;
					else F4--;
				}
			}
			else
			{
				a2[y]--;
				if (a2[y]==0)
				{
					if (a1[y]==0)cnt2++;
					else F1--;
					if (y&1)F4--;
					else F3--;
				}
			}
			t[mp(x,y)]=0;
		}
		if (opt==0)
		{
			t[mp(x,y)]=2;
			int a=y&1?1:2;
			if (a==1)
			{
				a3[x]++;
				if (a3[x]==1)
				{
					if (a4[x]==0)cnt--;
					else F++;
				}
			}
			if (a==2)
			{
				a4[x]++;
				if (a4[x]==1)
				{
					if (a3[x]==0)cnt--;
					else F++;
				}
			}
			if ((x+opt)&1)
			{
				a1[y]++;
				if (a1[y]==1)
				{
					if (a2[y]==0)cnt2--;
					else F1++;
					if (y&1)F3++;
					else F4++;
				}
			}
			else
			{
				a2[y]++;
				if (a2[y]==1)
				{
					if (a1[y]==0)cnt2--;
					else F1++;
					if (y&1)F4++;
					else F3++;
				}
			}
		}
		if (opt==1)
		{
			t[mp(x,y)]=1;
			int a=y&1?2:1;
			if (a==1)
			{
				a3[x]++;
				if (a3[x]==1)
				{
					if (a4[x]==0)cnt--;
					else F++;
				}
			}
			if (a==2)
			{
				a4[x]++;
				if (a4[x]==1)
				{
					if (a3[x]==0)cnt--;
					else F++;
				}
			}
			if ((x+opt)&1)
			{
				a1[y]++;
				if (a1[y]==1)
				{
					if (a2[y]==0)cnt2--;
					else F1++;
					if (y&1)F3++;
					else F4++;
				}
			}
			else
			{
				a2[y]++;
				if (a2[y]==1)
				{
					if (a1[y]==0)cnt2--;
					else F1++;
					if (y&1)F4++;
					else F3++;
				}
			}
		}
		int res=0;
		if (!F)res+=poww(2,cnt);
		if (!F1)res+=poww(2,cnt2);
		if (!F3)res--;
		if (!F4)res--;
//		cout<<cnt<<' '<<cnt2<<' '<<F<<' '<<F1<<' '<<F3<<' '<<F4<<' ';
		res=(res%Mod+Mod)%Mod;
		cout<<res<<endl;
	}
	return 0;
}
//?