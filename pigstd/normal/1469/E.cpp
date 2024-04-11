#include<bits/stdc++.h>
#define int long long
#define hash jihlkjwljh
using namespace std;

const int Mod=1145141919180;
const int M=1e6+10;
int a[M],n,T,k,pow2[M],hash[M];

map<int,bool>t;

void init()
{
	pow2[0]=1;
	for (int i=1;i<=1e6;i++)pow2[i]=pow2[i-1]*2%Mod;
}

signed main()
{
	cin>>T;init();
	while(T--)
	{
		cin>>n>>k;string s;cin>>s;
		for (int i=1;i<=n;i++)a[i]=s[i-1]-'0',a[i]^=1;
		hash[1]=0;int cnt=0;
		for (int i=1;i<=k;i++)
			hash[1]=(hash[1]+pow2[k-i]*a[i])%Mod;
		for (int l=2,r=1+k;r<=n;r++,l++)
			hash[l]=(((hash[l-1]-a[l-1]*pow2[k-1])*2+a[r])%Mod+Mod)%Mod;
		for (int i=1;i<=n-k+1;i++)
		{
			t[hash[i]]=1;
			if (hash[i]!=hash[i-1])cnt++;
			if (hash[i]==0&&i==1)cnt++;
		}
		string ans="";bool f=0;int ff=log2(cnt);
		ff++;
//		if (ff>k){puts("NO");
////		for (int i=1;i<=n-k+1;i++)
	//		t[hash[i]]=0;
	//	continue;}
		for (int i=1;i<=max(0ll,k-ff);i++)ans+="0";
		for (int i=0;i<(1ll<<min(ff,k));i++)
			if (!t[i])
			{
				for (int j=min(ff,k)-1;j>=0;j--)
					if ((1<<j)&i)ans+="1";
					else ans+="0";
				f=1;break;
			}
		if (!f)puts("NO");
		else puts("YES"),cout<<ans<<endl;
		for (int i=1;i<=n-k+1;i++)
			t[hash[i]]=0;
	}
	return 0;
}
/*
1
10 10
1111111111
*/