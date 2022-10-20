#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=4e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[70];
int id[256],in[M],out[M];
vector<int>e[N],ans;
void dfs(int now)
{
	while (!e[now].empty())
	{
		int to=e[now].back();
		e[now].pop_back();
		dfs(to);
		ans.push_back(to);
	}
}

signed main()
{
	int cnt=0;
	for (int i='a';i<='z';i++) s[id[i]=cnt++]=i;
	for (int i='A';i<='Z';i++) s[id[i]=cnt++]=i;
	for (int i='0';i<='9';i++) s[id[i]=cnt++]=i;
	int m=read();
	for (int i=1;i<=m;i++)
	{
		char a[3];
		scanf("%s",a);
		int x=id[a[0]],y=id[a[1]],z=id[a[2]];
		int u=x*cnt+y,v=y*cnt+z;
		e[u].push_back(v);
		in[v]++,out[u]++;
	}
	int c1=0,c2=0,c3=0;
	for (int i=0;i<cnt*cnt;i++)
	if (in[i]==out[i]) c2++;
	else if (in[i]==out[i]-1) c1++;
	else if (in[i]==out[i]+1) c3++;
	else return puts("NO"),0;
	int st=-1;
	if (c1==0&&c3==0){for (int i=0;i<cnt*cnt;i++) if (out[i]) st=i;}
	else if (c1==1&&c3==1){for (int i=0;i<cnt*cnt;i++) if (in[i]==out[i]-1) st=i;}
	else return puts("NO"),0;
	assert(~st);
	dfs(st);
	if (ans.size()!=m) return puts("NO"),0;
	puts("YES");
	reverse(ans.begin(),ans.end());
	putchar(s[st/cnt]);
	putchar(s[st%cnt]);
	for (int i:ans) putchar(s[i%cnt]);
	
	return 0;
}