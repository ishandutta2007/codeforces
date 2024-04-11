#include<cstdio>
int n,fa[26],ans,ll[200000],rr[200000];
char s[200000],t[200000];
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main(){
	for(int i=0;i<26;++i) fa[i]=i;
	scanf("%d%s%s",&n,s,t);
	for(int i=0;i<n;++i){
		int l=s[i]-'a',r=t[i]-'a';
		l=getf(l); r=getf(r);
		if(l!=r){
			++ans; fa[l]=r; ll[ans]=l; rr[ans]=r;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i) printf("%c %c\n",ll[i]+'a',rr[i]+'a');
}