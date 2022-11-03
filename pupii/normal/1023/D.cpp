#include<bits/stdc++.h>
int a[500010];
int n,q;
int main(){ 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<n;++i)
	    if(a[i]&&a[i-1]>a[i]&&a[i+1]>a[i])
	        {puts("NO");return 0;}
	bool flg=0;
	for(int i=1;i<=n;++i)if(a[i]==q)flg=1;
	int mx=0;
	for(int i=1;i<=n;++i){
	    if(!flg&&mx!=q&&a[i]==0)a[i]=q;
	    if(a[i]==0)a[i]=a[i-1];
	    mx=std::max(mx,a[i]);
	}
	for(int i=n;i;--i)if(a[i]==0)a[i]=a[i+1];
	if(mx<q){puts("NO");return 0;}
	else puts("YES");
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}