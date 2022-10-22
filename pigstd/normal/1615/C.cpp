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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

int n;
string s1,s2;

signed main()
{
	WT
	{
		cin>>n>>s1>>s2;
		int cnt1=0,cnt2=0;
		for (int i=0;i<n;i++)cnt1+=s1[i]-'0';
		for (int i=0;i<n;i++)cnt2+=s2[i]-'0';
//		cout<<cnt1<<' '<<cnt2<<'\n';
		if (cnt1!=cnt2&&cnt1+cnt2!=n+1){puts("-1");continue;}
		int res1=0,res2=0;
		for (int i=0;i<n;i++)res1+=s1[i]!=s2[i];
		for (int i=0;i<n;i++)res2+=s1[i]==s2[i];
		int F1=0,F2=0,ans=0;
		if (cnt1==cnt2)F1=1;
		if (cnt1+cnt2==n+1)F2=1;
		if (F1&&F2)ans=min(res1,res2);
		else if (F1)ans=res1;
		else ans=res2;
		cout<<ans<<'\n';
	}
	return 0;
}