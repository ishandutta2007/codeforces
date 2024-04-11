#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,blo,cnt;
ll a[500005],st[805],en[805],b[500005],bl[500005],lazy[805];

int main(){
	n=readint(); q=readint();
	blo=700;
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i+=blo) st[++cnt]=i,en[cnt]=i+blo-1;
	en[cnt]=n;
	for(int i=1;i<=cnt;i++) for(int j=st[i];j<=en[i];j++) bl[j]=i;
	memcpy(b,a,sizeof(b));
	for(int i=1;i<=cnt;i++) sort(b+st[i],b+en[i]+1);
	int opt,x;
	while(q--){
		opt=readint(); x=readint();
		if(opt==1){
			int lb=bl[x],y=readint(),rb=bl[y],z=readint();
			if(lb==rb){
				for(int i=x;i<=y;i++) a[i]+=z;
				for(int i=st[lb];i<=en[lb];i++) b[i]=a[i];
				sort(b+st[lb],b+en[lb]+1);
			}
			else{
				for(int i=x;i<=en[lb];i++) a[i]+=z;
				for(int i=st[lb];i<=en[lb];i++) b[i]=a[i];
				sort(b+st[lb],b+en[lb]+1);
				for(int i=st[rb];i<=y;i++) a[i]+=z;
				for(int i=st[rb];i<=en[rb];i++) b[i]=a[i];
				sort(b+st[rb],b+en[rb]+1);
				for(int i=lb+1;i<=rb-1;i++) lazy[i]+=z;
			}
		}
		else{
			int l=-1,r=-1;
			for(int i=1;i<=cnt;i++){
				if(b[lower_bound(b+st[i],b+en[i]+1,x-lazy[i])-b]==x-lazy[i]){
					l=i;
					break;
				}
			}
			for(int i=cnt;i>=1;i--){
				if(b[lower_bound(b+st[i],b+en[i]+1,x-lazy[i])-b]==x-lazy[i]){
					r=i;
					break;
				}
			}
			if(l==-1){
				printf("-1\n");
				continue;
			}
			for(int i=st[l];i<=en[l];i++){
				if(a[i]+lazy[l]==x){
					l=i;
					break;
				}
			}
			for(int i=en[r];i>=st[r];i--){
				if(a[i]+lazy[r]==x){
					r=i;
					break;
				}
			}
			printf("%d\n",r-l);
		}
	}
	return 0;
}