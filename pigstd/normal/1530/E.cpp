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

const int M=1e5+10;
int a[M],n,t[30];
string s;
vector<int>v;

signed main()
{
	WT
	{
		cin>>s;n=s.size();
		for (int i=1;i<=26;i++)t[i]=0;
		for (int i=0;i<n;i++)a[i+1]=s[i]-'a'+1,t[a[i+1]]++;
		int p=-1;
		for (int i=1;i<=26;i++)if (t[i]==1){p=i;break;}
		if (p!=-1)
		{
			cout<<char(p+'a'-1);v.clear();
			for (int i=1;i<=n;i++)v.pb(a[i]);
			sort(v.begin(),v.end());
			for (int i=0;i<n;i++)
				if (v[i]!=p)cout<<char(v[i]+'a'-1);puts("");
			continue;
		}
		int minn1=1e9,sum1=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<minn1)minn1=a[i],sum1=0;
			if (a[i]==minn1)sum1++;
		}
		if (sum1==n)
		{
			cout<<s<<endl;
			continue;
		}
		if (sum1-(n-sum1)<=2)
		{
			v.clear();
			for (int i=1;i<=n;i++)
				if (a[i]!=minn1)v.pb(a[i]);
			sort(v.begin(),v.end());
			cout<<char(minn1+'a'-1);sum1--;
			for (int i=0;i<v.size();i++)
			{
				if (sum1!=0)sum1--,cout<<char(minn1+'a'-1);
				cout<<char(v[i]+'a'-1);
			}if (sum1!=0)cout<<char(minn1+'a'-1);
			puts("");continue;
		}
		int minn2=1e9,sum2=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==minn1)continue;
			if (a[i]<minn2)minn2=a[i],sum2=0;
			if (a[i]==minn2)sum2++;
		}
		if (sum1+sum2==n)
		{
			cout<<char(minn1+'a'-1);
			for (int i=1;i<=sum2;i++)cout<<char(minn2+'a'-1);
			for (int i=1;i<=sum1-1;i++)cout<<char(minn1+'a'-1);
		}
		else
		{
			cout<<char(minn1+'a'-1)<<char(minn2+'a'-1);
			for (int i=1;i<=sum1-1;i++)cout<<char(minn1+'a'-1);
			v.clear();
			for (int i=1;i<=n;i++)
				if (a[i]!=minn1&&a[i]!=minn2)v.pb(a[i]);
			sort(v.begin(),v.end());
			cout<<char(v[0]+'a'-1);
			for (int i=1;i<=sum2-1;i++)cout<<char(minn2+'a'-1);
			for (int i=1;i<v.size();i++)
				cout<<char(v[i]+'a'-1);
		}puts("");
	}
	return 0;
}