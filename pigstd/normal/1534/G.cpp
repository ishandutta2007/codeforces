#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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

const int M=8e5+10;
int n,x[M],y[M],tag,s,k;
pii p[M];

priority_queue<int>q1,q2;

signed main()
{
	n=read();k=-n;
	for (int i=1;i<=n;i++)x[i]=read(),y[i]=read(),p[i]=mp(x[i]+y[i],x[i]),s+=x[i];
	sort(p+1,p+1+n);
	int lst=p[1].x;
	q1.push(p[1].y),q2.push(-p[1].y);
	for (int i=2;i<=n;i++)
	{
		tag+=p[i].x-lst,lst=p[i].x;
		if (p[i].y<q1.top())q2.push(-q1.top()+tag),q1.pop(),q1.push(p[i].y),q1.push(p[i].y);
		else if (p[i].y>-q2.top()+tag)q1.push(-q2.top()+tag),q2.pop(),q2.push(-p[i].y+tag),q2.push(-p[i].y+tag);
		else q1.push(p[i].y),q2.push(-p[i].y+tag);
	}
	vector<int>v;
	while(!q1.empty())v.pb(q1.top()),q1.pop();
	reverse(v.begin(),v.end());
	lst=0;
	for (auto x:v)s+=(x-lst)*k,k++,lst=x;
	cout<<s<<'\n';
	return 0;
}