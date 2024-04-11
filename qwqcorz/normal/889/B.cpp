#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int siz[26];
bool e[26][26],vis[26];
char a[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		int m=strlen(a+1);
		for (int j=1;j<m;j++) e[a[j]-'a'][a[j+1]-'a']=1;
		for (int j=1;j<=m;j++) vis[a[j]-'a']=1;
	}
	for (int i=0;i<26;i++)
	for (int j=0;j<26;j++) siz[j]+=e[i][j];
	deque<int>q;
	for (int i=0;i<26;i++) if (vis[i]&&!siz[i]) q.push_back(i);
	string ans;
	while (!q.empty())
	{
		int now=q.front(); q.pop_front(),vis[now]=0;
		ans+=char(now+'a');
		for (int i=0;i<26;i++) if (e[now][i]) if (!--siz[i]) q.push_front(i);
	}
	for (int i=0;i<26;i++) if (vis[i]) return puts("NO"),void();
	int m=ans.size();
	for (int i=0;i<m;i++)
	for (int j=0;j<m;j++) if (j!=i+1&&e[ans[i]-'a'][ans[j]-'a']) return puts("NO"),void();
	cout<<ans<<endl;
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}