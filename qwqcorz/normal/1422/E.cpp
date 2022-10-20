#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int top=0;
char a[N],d[N];
deque<char>q;
pair<int,string>ans[N];
bool check(char x)
{
	if (q.empty()) return 0;
	char c=q.front(),ch=d[top-1];
	return x==c&&x>ch;
}

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for (int i=n,can=1;i>=1;i--)
	{
		if (check(a[i])&&can) can=0,q.pop_front(),top-=q.empty()||d[top]!=q.front();
						 else can=1,q.empty()||q.front()!=a[i]?d[++top]=a[i]:0,q.push_front(a[i]);
		ans[i].first=q.size();
		if (q.size()<=10) for (char j:q) ans[i].second+=j;
		else
		{
			auto now=q.begin();
			for (int j=1;j<=5;j++) ans[i].second+=*(now++);
			for (int j=1;j<=3;j++) ans[i].second+='.';
			now=prev(prev(q.end()));
			for (int j=1;j<=2;j++) ans[i].second+=*(now++);
		}
	}
	for (int i=1;i<=n;i++)
	{
		print(ans[i].first,' ');
		cout<<ans[i].second<<'\n';
	}
	
	return 0;
}