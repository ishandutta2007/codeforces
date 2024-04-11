#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define pb push_back
using namespace std;
const int N=1e5+55;
const int B=300;
int n,q,opt,l,r;
int x,y;
int a[N],id[N];
int tot=0;
struct sqr{
	int l,r,len;
	bool flag;
	int fa[B+5];
	int less;
	void change(){
		flag=1;
		for(int i=l;i<=r;i++){
			if(id[a[i]]!=id[i])fa[i-l]=a[i];
			else fa[i-l]=fa[a[i]-l],flag=0;;
		}
	}
	void init(){
		for(int i=l;i<=r;i++){
			id[i]=tot;
		}
		change();
	}
	void les(int x){
		if(!flag){
			for(int i=l;i<=r;i++){
				a[i]=max(a[i]-x,1);
			}
			a[1]=0;
			change();
		}
		else{
			less+=x;
			less=min(less,n);
		}
	}
}b[B*300];
void prework(){
	int l=1,r=B;
	for(;;){
		tot++;
		r=min(l+B-1,n);
		b[tot].l=l;
		b[tot].r=r;
		b[tot].init();
		l=r+1;
		if(r==n)break;
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("data.in","r",stdin);
	#endif
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
	}
	prework();
	for(int i=1;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&l,&r,&x);
			if(id[l]==id[r]){
				for(int k=l;k<=r;k++)a[k]=max(a[k]-x,1);
				a[1]=0;
				b[id[l]].change();
			}
			else if(id[l]+1==id[r]){
				for(int k=l;k<=B*id[l];k++)a[k]=max(a[k]-x,1);
				a[1]=0;
				b[id[l]].change();
				for(int k=B*id[l]+1;k<=r;k++)a[k]=max(a[k]-x,1);
				a[1]=0;
				b[id[r]].change();
			}
			else {
				for(int k=l;k<=B*id[l];k++)a[k]=max(a[k]-x,1);
				a[1]=0;
				b[id[l]].change();
				for(int k=B*(id[r]-1)+1;k<=r;k++)a[k]=max(a[k]-x,1);
				a[1]=0;
				b[id[r]].change();
				for(int k=id[l]+1;k<id[r];k++){
					b[k].les(x);
				}
			}
		}
		else{
			scanf("%d%d",&x,&y);
			while(1){
				if(id[x]<id[y])swap(x,y);
				if(id[x]!=id[y]){
					int L=b[id[x]].l;
					x=max(1,b[id[x]].fa[x-L]-b[id[x]].less);
				}
				else{
					if(b[id[x]].fa[x-b[id[x]].l]!=b[id[y]].fa[y-b[id[y]].l]){
						x=max(1,b[id[x]].fa[x-b[id[x]].l]-b[id[x]].less);
						y=max(1,b[id[y]].fa[y-b[id[y]].l]-b[id[y]].less);
					}
					else break;
				}
			}
			while(a[x]!=a[y]){
				if(x<y)swap(x,y);
				x=max(a[x]-b[id[x]].less,1);
			}
			int f=max(x==y?x:a[x]-b[id[x]].less,1);
			printf("%d\n",f);
		}
	}
	return 0;
}