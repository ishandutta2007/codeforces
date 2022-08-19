#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int id,l,r;
	bool operator<(const node c)const{
		if(l==c.l) return r<c.r;
		return l<c.l;
	}
}k[100005];

int t,n;
int ans[100005],maxa[100005],mina[100005];

int main(){
	t=readint();
	while(t--){
		n=readint();
		for(int i=1;i<=n;i++) k[i].id=i,k[i].l=readint(),k[i].r=readint();
		sort(k+1,k+n+1);
		int ret=-1;
		maxa[0]=0,mina[n+1]=1<<30;
		for(int i=1;i<=n;i++) maxa[i]=max(maxa[i-1],k[i].r);
		for(int i=n;i>=1;i--) mina[i]=min(mina[i+1],k[i].l);
		for(int i=1;i<=n-1;i++){
			if(maxa[i]<mina[i+1]){
				ret=i;
				break;
			}
		}
		if(ret<0) printf("-1\n");
		else{
			for(int i=1;i<=ret;i++) ans[k[i].id]=1;
			for(int i=ret+1;i<=n;i++) ans[k[i].id]=2;
			for(int i=1;i<=n;i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}