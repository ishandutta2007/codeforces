#include<bits/stdc++.h>
#define double long double
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct vector{double x,y;}O;
vector operator+(vector a,vector b){return{a.x+b.x,a.y+b.y};}
vector operator-(vector a,vector b){return{a.x-b.x,a.y-b.y};}
vector operator*(vector a,double b){return{a.x*b,a.y*b};}
double operator^(vector a,vector b){return a.x*b.y-a.y*b.x;}
double sqr(double x){return x*x;}
double len(vector x){return sqr(x.x)+sqr(x.y);}
double lk[50010],lb[50010],dist[50010],ang[50010];
struct fuck{double p;int i;bool s;}st[100010];
int N,n,m,pl[50010],pr[50010],rpl[50010];
int t[50010];
void update(int x,int o){while(x<=n)t[x]+=o,x+=x&-x;};
int query(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
const double pi=acos(-1);
bool chk(double mid,bool out=0){
	N=0;
	for(int i=1;i<=n;++i)
		if(dist[i]<mid){
			double s=acosl(dist[i]/mid),p1=ang[i]-s,p2=ang[i]+s;
			if(p1<-pi)p1+=2*pi;if(p2>pi)p2-=2*pi;
			if(p1>p2)std::swap(p1,p2);
			st[++N]={p1,i,0};
			st[++N]={p2,i,1};
		}
	std::sort(st+1,st+N+1,[](fuck a,fuck b){return a.p<b.p;});
	memset(t,0,sizeof t);memset(pr,0,sizeof pr);
	for(int i=N,p=n;i;--i)
		if(pr[st[i].i])pl[st[i].i]=p--;
		else pr[st[i].i]=i;
	if(out)return 0;
	ll cnt=0;
	for(int i=N,c=0;i;--i)
		if(pr[st[i].i]==i){
			cnt+=c-query(pl[st[i].i]);
			++c,update(pl[st[i].i],1);
		}else --c,update(pl[st[i].i],-1);
	return cnt>=m;
}
vector cross(int x,int y){
	vector sx={0,lb[x]},a={1,lk[x]},sy={0,lb[y]},b={1,lk[y]};
	vector c=sy-sx;
	double base=(b^c)/(b^a);
	return sx+a*base;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	{double x=gi()*1e-3,y=gi()*1e-3;O={x,y};}
	m=gi();
	for(int i=1;i<=n;++i){
		lk[i]=gi()*1e-3,lb[i]=gi()*1e-3;
		ang[i]=atanl(lk[i]);
		if(lk[i]*O.x+lb[i]>O.y)ang[i]+=0.5*pi;
		else ang[i]-=0.5*pi;
		dist[i]=fabsl(lk[i]*O.x+lb[i]-O.y)/sqrtl(1+lk[i]*lk[i]);
	}
	double l=0,r=1e10,mid;int time=100;
	while(time--){
		mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid;
	}
	for(int i=1;i<=n;++i)pl[i]=0;
	chk(l-1e-7,1);
	std::set<int>S;
	std::set<int>::iterator it;
	double ans=0;int cnt=0;
	for(int i=1;i<=n;++i)rpl[pl[i]]=i;
	fprintf(stderr,"1");
	for(int i=N;i;--i)
		if(pr[st[i].i]==i){
			it=S.lower_bound(pl[st[i].i]);
			while(it!=S.end())ans+=sqrtl(len(O-cross(st[i].i,rpl[*it]))),++it,++cnt;
			S.insert(pl[st[i].i]);
		}else S.erase(pl[st[i].i]);
	printf("%.10Lf\n",ans+l*(m-cnt));
	return 0;
}