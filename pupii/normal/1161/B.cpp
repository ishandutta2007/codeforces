// B
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
std::set<std::pair<int,int> >st[100010];
std::bitset<200010>bit,I,B,C;
il bool nmd(int n,int g){
	for(int i=1;i<n;++i)
		for(auto j:st[i]){
			int a=j.first,b=j.second;
			a=(a+g-1)%n+1,b=(b+g-1)%n+1;
			if(st[i].find({a,b})==st[i].end()&&st[i].find({b,a})==st[i].end())return 0;
		}
	puts("Yes");exit(0);
}
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	ll n=gi(),m=gi(),a,b,c;
	for(int i=1;i<=m;++i){
		a=gi(),b=gi();if(a>b)std::swap(a,b);
		c=std::min(b-a,a+n-b);
		if(b-a!=c)std::swap(a,b);
		if(c*2==n)st[c].insert({b,a}),st[c].insert({a,b});
		else st[c].insert({a,b});
	}
	for(int i=1;i*i<=n;++i)
		if(n%i==0){
			nmd(n,i);
			if(i*i!=n&&i!=1)nmd(n,n/i);
		}
	puts("No");
	return 0;
}