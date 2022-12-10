#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 998244353

using namespace std;

int i,j,m,n,p,k,t[N],ans[N],Ans;

char c[N];

int main()
{
		scanf("%d",&n);
		scanf("%s",c+1);
		int la=0;
		for (i=1;i<=n;++i)
		{
				if (!la) la=c[i];
				else if (la!=c[i]) la=-1;
				t[i]=la;
		}
		for (i='a';i<='z';++i) ans[i]++;
		for (i=1;i<=n;++i) if (t[i]>=0) ans[t[i]]++; 
		la=0;
		for (i=0;i<26;++i) (Ans+=ans[i+'a'])%Mo;
		for (i=n;i>=1;--i) 
		{
				if (t[i]>=0)
				ans[t[i]]--;
				if (!la) la=c[i];
				else if (la!=c[i]) la=-1;
				if (la!=-1) Ans=(Ans+ans[la])%Mo;
		}
		printf("%d\n",(Ans-25+Mo)%Mo); 
}