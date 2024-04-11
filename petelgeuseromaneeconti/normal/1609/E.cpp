#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int n,Q;
char s[N];
struct node{
	int a[3][3];
	node operator+(const node&b)const{
		node c;
		memset(c.a,63,sizeof(c.a));
		rep(x,0,2)rep(y,x,2)rep(z,y,2){
			c.a[x][z]=min(c.a[x][z],a[x][y]+b.a[y][z]);
		}
		return c;
	}
}t[N*4];
void upd(int k1){
	t[k1]=t[k1*2]+t[k1*2+1];
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		memset(t[k1].a,63,sizeof(t[k1].a));
		rep(x,0,2){
			t[k1].a[x][x]=(s[k2]==x);
			rep(y,x+1,2){
				t[k1].a[x][y]=0;
			}
		}
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4){
	if(k2==k3){
		memset(t[k1].a,63,sizeof(t[k1].a));
		rep(x,0,2){
			t[k1].a[x][x]=(s[k2]==x);
			rep(y,x+1,2){
				t[k1].a[x][y]=0;
			}
		}
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4);
	else mdf(k1*2+1,mid+1,k3,k4);
	upd(k1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	rep(i,1,n)s[i]-='a';
	bud(1,1,n);
	rep(_,1,Q){
		int pos;
		int c;
		scanf("%d",&pos);
		while(!islower(c=getchar()));
		c-='a';
		s[pos]=c;
		mdf(1,1,n,pos);
		printf("%d\n",min({t[1].a[0][0],t[1].a[0][1],t[1].a[0][2]}));
	}
	return 0;
}