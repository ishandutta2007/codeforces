#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))f^=ch=='-',ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f?x:-x;
}
int a[200010],b[200010];
int main(){
	int n=gi(),m=gi(),ta=gi(),tb=gi(),k=gi(),ans=0;
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=1;i<=m;++i)b[i]=gi();
	if(k>=n)return puts("-1"),0;
	for(int i=1,p=1;i<=n;++i){
		if(i>k+1)break;
		while(p<=m&&b[p]<a[i]+ta)++p;
		int rest=k-i+1;
		if(p+rest>m)return puts("-1"),0;
		else ans=std::max(ans,b[p+rest]+tb);
	}
	printf("%d\n",ans);
    return 0;
}