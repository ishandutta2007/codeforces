// bobkaiiy
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
int cnt[26];
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	std::string s;std::cin>>s;int n=s.size();
	for(int i=0;i<n;++i)if(s[i]=='a')++cnt[0];else ++cnt[1];
	printf("%d\n",n-std::max(0,cnt[1]-cnt[0]+1));
	return 0;
}