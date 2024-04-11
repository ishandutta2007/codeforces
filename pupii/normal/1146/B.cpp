// byykaoii
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
int pre[100010],suf[100010];
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	std::string s;std::cin>>s;s=' '+s;int n=s.size()-1;
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+(s[i]!='a');
	for(int i=n;i;--i)suf[i]=suf[i+1]+(s[i]!='a');
	int i=n+1;
	while(i>1&&s[i-1]!='a')--i;
	for(int j=i;j<=n+1;++j)
		if(pre[j-1]==suf[j]){
			int p1=0,p2=j-1;
			std::string ans;
			for(int k=1;k<=n-j+1;++k){
				++p1;while(s[p1]=='a')++p1;
				++p2;
				if(s[p1]!=s[p2])return puts(":("),0;
			}
			for(int k=1;k<j;++k)ans+=s[k];
			std::cout<<ans;
			return 0;
		}
	puts(":(");
	return 0;
}