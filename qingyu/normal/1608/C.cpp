#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,a[N],b[N],f[N];
set<pair<int,int>>s,t;
void mark(int x)
{
	f[x]=1;
	s.erase(make_pair(-a[x],x));
	t.erase(make_pair(-b[x],x));
	while(!s.empty() && (*s.begin()).first<-a[x]){
		auto pi=*s.begin();
		mark(pi.second);
		s.erase(pi);
	}
	while(!t.empty() && (*t.begin()).first<-b[x]){
		auto pi=*t.begin();
		mark(pi.second);
		t.erase(pi);
	}
}
void init()
{
	s.clear();
	t.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)f[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		s.insert(make_pair(-a[i],i));
		t.insert(make_pair(-b[i],i));
	}
	int x=(*s.begin()).second;
	int y=(*t.begin()).second;
	mark(x);
	if(x!=y && f[y]==0)mark(y);
	for(int i=1;i<=n;i++)printf("%d",f[i]?1:0);
	putchar('\n');
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)init();
}