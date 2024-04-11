#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
#ifndef MY
	#define putchar IO::_putchar
	#define getchar IO::_getchar
#endif
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read()
{
    int x=0,p=1;
	char c=getchar();
    while (c<'0' || c>'9'){
    	if (c=='-') p=-1;
    	c=getchar();
	}
    while (c>='0' && c<='9') x=x*10+c-48,c=getchar();
    return x*p;
}
const int Maxn=100005;
const LL mod=998244353;
LL qp(LL x,LL p){
	LL ret=1;
	while (p){
		if (p&1) ret=ret*x%mod;
		x=x*x%mod;
		p>>=1;
	} 
	return ret;
}
LL inv(LL x){
	return qp(x,mod-2);
}
struct mat{
	LL A[4][4];
	int x,y;
	mat(int _x=0,int _y=0){
		x=_x,y=_y;memset(A,0,sizeof(A));
	}
};
mat mul(mat x,mat y){
	mat z(x.x,y.y);
	for (int i=0;i<x.x;i++){
		for (int j=0;j<y.y;j++){
			for (int k=0;k<x.y;k++){
				z.A[i][j]+=x.A[i][k]*y.A[k][j];
			}
			z.A[i][j]%=mod;
		}
	}
	return z;
}
mat tree[Maxn*4];
int n;
LL x[Maxn],pl[Maxn],pr[Maxn],v[Maxn];
mat cur[Maxn];
struct T{
	LL X,Y;
	int id;
	int d1,d2;
	T(LL _X,LL _Y,int _id,int _d1,int _d2){
		X=_X,Y=_Y;
		id=_id;d1=_d1;d2=_d2; 
	}
	T(){
		;
	}
};
bool cmp(T A,T B){
	if (A.Y==0 && B.Y==0) return false;
	if (A.Y==0) return true;
	if (B.Y==0) return false;
	return A.X*B.Y>A.Y*B.X;
}
void modify(int p,int l,int r,int pos){
	if (l==r){
		tree[p]=cur[pos];
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid){
		modify(p*2,l,mid,pos);
	}
	else{
		modify(p*2+1,mid+1,r,pos);
	}
	tree[p]=mul(tree[p*2],tree[p*2+1]); 
}
LL Calc(){
	mat tmp=tree[1];
	mat ini(1,2);
	ini.A[0][0]=pl[1];ini.A[0][1]=pr[1];
	ini=mul(ini,tmp);
	return (ini.A[0][0]+ini.A[0][1])%mod;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		LL p;
		scanf("%lld%lld%lld",&x[i],&v[i],&p);
		p=p*inv(100)%mod;
		pr[i]=p;pl[i]=(1+mod-p)%mod;
	}
	vector<T> V;
	for (int i=1;i<=n-1;i++){
		int dif=x[i+1]-x[i];
		V.pb(T(dif,v[i]+v[i+1],i,1,0));
		V.pb(T(dif,0,i,0,1));
		if (v[i]>v[i+1]){
			V.pb(T(dif,v[i]-v[i+1],i,1,1));
		}
		else{
			V.pb(T(dif,0,i,1,1));
		}
		if (v[i+1]>v[i]){
			V.pb(T(dif,v[i+1]-v[i],i,0,0));
		}
		else{
			V.pb(T(dif,0,i,0,0));
		}
	}
	sort(V.begin(),V.end(),cmp);
	for (int i=0;i<Maxn*4;i++) tree[i].x=tree[i].y=2;
	for (int i=1;i<=n-1;i++) cur[i].x=cur[i].y=2;
	LL lstp=0;
	LL res=0;
	for (int i=0;i<V.size();i++){
		LL t=V[i].X*inv(V[i].Y)%mod;
		int pos=V[i].id;
		LL p=(V[i].d2)?pr[pos+1]:pl[pos+1];
		cur[pos].A[V[i].d1][V[i].d2]=p;
		modify(1,1,n-1,pos);
		LL np=Calc();
		LL dlt=(np-lstp+mod)%mod;
		if (V[i].Y){
			res+=t*dlt;
			res%=mod;
		}
		lstp=np;
	}
	printf("%lld\n",res);
	return ~~(0^_^0);
}