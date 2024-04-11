#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T;cin>>T;while(T--) 
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

const int M=3e5+10;
int n,ans[M],cnt[M];
string s1,s2,s3;
string ss1,ss2;

signed main()
{
	WT
	{
		int n;cin>>n;
		cin>>s1>>s2>>s3;
		int cnt1=0,cnt2=0,cnt3=0;
		for (int i=0;i<2*n;i++)
			cnt1+=s1[i]-'0',
			cnt2+=s2[i]-'0',
			cnt3+=s3[i]-'0';
		if ((cnt1>=n&&cnt2>=n)||(cnt1<=n&&cnt2<=n))
			ss1=s1,ss2=s2;
		if ((cnt1>=n&&cnt3>=n)||(cnt1<=n&&cnt3<=n))
			ss1=s1,ss2=s3;
		if ((cnt2>=n&&cnt3>=n)||(cnt2<=n&&cnt3<=n))
			ss1=s2,ss2=s3;
		cnt1=cnt2=0;
		for (int i=0;i<2*n;i++)
			cnt1+=ss1[i]-'0',
			cnt2+=ss2[i]-'0';
		if (max(cnt1,cnt2)<=n)
		{
			int maxn=2*n-min(cnt1,cnt2),p=0;
			for (int i=0;i<2*n;i++)
				if (ss1[i]=='1')cnt[p]++;
				else p++;p=0;
			for (int i=0;i<2*n;i++)
				if (ss2[i]=='1')cnt[p]++;
				else p++;
			for (int i=0;i<=maxn;i++)
			{
				if (i!=0)cout<<'0';
				while(cnt[i]--)cout<<'1';
				cnt[i]++;
			}
		}
		else
		{
			int maxn=max(cnt1,cnt2),p=0;
			for (int i=0;i<2*n;i++)
				if (ss1[i]=='0')cnt[p]++;
				else p++;p=0;
			for (int i=0;i<2*n;i++)
				if (ss2[i]=='0')cnt[p]++;
				else p++;
			for (int i=0;i<=maxn;i++)
			{
				if (i!=0)cout<<'1';
				while(cnt[i]--)cout<<'0';
				cnt[i]++;
			}
		}
		puts("");
//		for (int i=0;i<=3*n;i++)cnt[i]=0;
	}
	return 0;
}