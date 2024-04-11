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
int cn[1010],cm[1010];
int main(){
	int n=gi();
	for(int i=1;i<n;++i){
		printf("? %d %d %d %d\n",1,1,i,n);
		fflush(stdout);
		cn[i]=gi();
	}
	for(int i=1;i<n;++i){
		printf("? %d %d %d %d\n",1,1,n,i);
		fflush(stdout);
		cm[i]=gi();
	}
	int x1,x2,y1,y2;
	{
		int mn=1e9,mx=0;
		for(int i=1;i<n;++i)if(cn[i]&1)mn=std::min(mn,i),mx=std::max(mx,i);
		if(mn==1e9&&mx==0)x1=x2=0;
		else x1=mn,x2=mx+1;
	}
	{
		int mn=1e9,mx=0;
		for(int i=1;i<n;++i)if(cm[i]&1)mn=std::min(mn,i),mx=std::max(mx,i);
		if(mn==1e9&&mx==0)y1=y2=0;
		else y1=mn,y2=mx+1;
	}
	if(x1==0&&x2==0){
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			printf("? %d %d %d %d\n",1,y1,mid,y1);
			fflush(stdout);
			if(gi()&1)r=mid;
			else l=mid+1;
		}
		x1=x2=l;
	}
	if(y1==0&&y2==0){
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			printf("? %d %d %d %d\n",x1,1,x1,mid);
			fflush(stdout);
			if(gi()&1)r=mid;
			else l=mid+1;
		}
		y1=y2=l;
	}
	printf("? %d %d %d %d\n",x1,y1,x1,y1);
	fflush(stdout);
	if(gi()!=1)std::swap(x1,x2);
	printf("! %d %d %d %d\n",x1,y1,x2,y2);
	return 0;
}