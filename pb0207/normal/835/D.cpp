#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=5e3+1e2+7,P=1e9+7,base=1313131;

ll hl[N],hr[N],lv[N][N],mi[N],n,ans[N];

char s[N];

void pre()
{
	mi[0]=1;
	for(int i=1;i<=n;i++)
		mi[i]=mi[i-1]*base%P;
	for(int i=1;i<=n;i++)
		hl[i]=hl[i-1]*base%P+s[i-1]%P;
	for(int i=n;i>=1;i--)
		hr[i]=hr[i+1]*base%P+s[i-1]%P;
}

ll gtl(ll l,ll r)
{
	return (hl[r]-hl[l-1]*mi[r-l+1]%P+P)%P;
}

ll gtr(ll l,ll r)
{
	return (hr[l]-hr[r+1]*mi[r-l+1]%P+P)%P;
}

bool ispl(ll l,ll r)
{
	if(r<l)
		return false;
	return gtl(l,r)==gtr(l,r);
}

int main()
{
	scanf("%s",s);
	n=strlen(s);
	pre();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			ll len=(j-i+1)>>1;
			if(ispl(i,j))
			{
				if(ispl(i,i+len-1)&&ispl(j-len+1,j))
					lv[i][j]=lv[i][i+len-1]+1;
				else
					lv[i][j]=1;
			}
			ans[lv[i][j]]++;
		}
	for(int i=n;i>=1;i--)
		ans[i]+=ans[i+1];
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}