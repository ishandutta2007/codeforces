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
char s[100010];
int len[26];
int main(){
	int yyb=gi(),n;
	for(int byy=1;byy<=yyb;++byy){
		scanf("%s",s+1);
		n=strlen(s+1);
		if(byy!=1){
			int l=1;while(l!=n&&s[l+1]==s[1])++l;
			int r=n;while(r!=1&&s[r-1]==s[n])--r;
			r=n-r+1;
			if(l==n){
				for(int i=0;i<26;++i)if(i!=s[1]-'a')len[i]=std::min(len[i],1);
				if(len[s[1]-'a'])len[s[1]-'a']=(len[s[1]-'a']+1)*(n+1)-1;
				else len[s[1]-'a']=n;
			}
			else{
				for(int i=0;i<26;++i)len[i]=std::min(len[i],1);
				len[s[1]-'a']+=l;
				len[s[n]-'a']+=r;
			}
		}
		for(int i=1,j;i<=n;i=j+1){
			j=i;while(j!=n&&s[j+1]==s[i])++j;
			len[s[i]-'a']=std::max(len[s[i]-'a'],j-i+1);
		}
	}
	int ans=0;
	for(int i=0;i<26;++i)ans=std::max(ans,len[i]);
	printf("%d\n",ans);
	return 0;
}