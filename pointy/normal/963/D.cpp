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

//const ll inf=1000000000000000000; 
const int inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=100005,M=26;
int n,q; 
char s[N],t[N];
bitset<N>a[M],ans;
int c[N],cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s+1) >> q;
	n=strlen(s+1);
	for (int i=1;i<=n;i++) a[s[i]-'a'][i]=1;
	for (int i=1;i<=q;i++)
	{
		int k;
		cin >> k >> (t+1);
		int len=strlen(t+1);
		ans.set();
		ans[0]=0;
		for (int j=1;j<=len;j++) ans&=a[t[j]-'a']<<(len-j);
		int res=inf;
		cnt=0;
		for (int j=ans._Find_first();j!=N;j=ans._Find_next(j)) c[++cnt]=j;
		for (int j=k;j<=cnt;j++) res=min(res,c[j]-c[j-k+1]+len);
		if (res>=inf) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}