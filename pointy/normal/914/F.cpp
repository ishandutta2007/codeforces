// Author: Little09
// Problem: CF914F Substrings in a String
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF914F
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=100005,M=26;
int n,q; 
char s[N],t[N];
bitset<N>a[M],ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s+1) >> q;
	n=strlen(s+1);
	for (int i=1;i<=n;i++) a[s[i]-'a'][i]=1;
	for (int i=1;i<=q;i++)
	{
		int tp;
		cin >> tp;
		if (tp==1)
		{
			int x;
			char y;
			cin >> x >> y;
			a[s[x]-'a'][x]=0;
			s[x]=y;
			a[s[x]-'a'][x]=1;
		}
		else 
		{
			int l,r;
			cin >> l >> r >> (t+1);
			int len=strlen(t+1);
			l+=len-1;
			if (l>r)
			{
				cout << 0 << endl;
				continue;
			}
			ans.set();
			ans[0]=0;
			for (int j=1;j<=len;j++) ans&=a[t[j]-'a']<<(len-j);
			int res=((ans>>l).count()-(ans>>(r+1)).count());
			cout << res << endl;
		}
	}
	return 0;
}