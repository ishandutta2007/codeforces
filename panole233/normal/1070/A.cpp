#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int inf = 0x3f3f3f3f;
int d,s,pre[505*5050],q[505*5050],res[505*5050],len;
int dy(int x, int y){return (x+1)*d+y;}
int main() {
	read(d);read(s);
	memset(pre,inf,sizeof(pre));
	pre[dy(0,0)]=0;int f=1,r=1;q[r++]=dy(0,0);
	while(f!=r){
		int u=q[f++];int sum=u/d-1,val=u%d;
		/*if(sum==6&&val==6)printf("%d %d\n",sum,val);
		if(sum==6+9&&val==69%13)printf("%d %d\n",sum,val);
		if(sum==6+9+9&&val==699%13)printf("%d %d\n",sum,val);
		if(sum==6+9+9+9+9&&val==69999%13)printf("%d %d\n",sum,val);
		if(sum==7&&val==7)printf("%d %d\n",sum,val);
		if(sum==7+7&&val==77%13)printf("%d %d\n",sum,val);
		if(sum==7+7+9&&val==779%13)printf("%d %d\n",sum,val);
		if(sum==7+7+9+9+9&&val==77999%13)printf("%d %d\n",sum,val);*/
	//	if(f<=100)printf("<%d,%d>\n",sum,val);
		rep(i,0,9)if(sum+i<=s+10){
			int v=dy(sum+i,(val*10+i)%d);
			if(pre[v]==inf){pre[v]=u;q[r++]=v;}
		}
	}
	/*printf("[%d %d]\n",pre[dy(6,6%13)]/d-1,pre[dy(6,6%13)]%d);
	printf("[%d]\n",pre[dy(6+9,69%13)]);
	printf("[%d]\n",pre[dy(6+9+9,699%13)]);
	printf("[%d]\n",pre[dy(6+9+9+9,6999%13)]);*/
	if(pre[dy(s,0)]==inf)puts("-1");
	else{
		for(int u=dy(s,0);pre[u];u=pre[u])
			res[++len]=u/d-pre[u]/d;//,printf("<%d,%d> <%d,%d>\n",u/d-1,u%d,pre[u]/d-1,u%d);
		per(i,len,1)printf("%d",res[i]);
	}
	return 0;
}