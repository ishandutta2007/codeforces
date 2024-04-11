#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
string rstr(){
	string ret;
	char buf[N];
	scanf("%s",&buf);
	return ret=buf;
}
char rchar(){
	char c=getchar();
	while(c==' '||c=='\n') c=getchar();
	return c;
}
double rdou(){
	double ret=0,uu=1,td=0.1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	while(c=='.') c=getchar();
	while(isdigit(c)) ret=ret+(c-'0')*td,td/=10,c=getchar();
	return ret*uu;
}
ll n,q,num[N];
char buf[N];
string s,t1,t2;
struct fk{
	ll a,b;
};
struct segment{
	ll l,r;
	fk val;
};
segment segt[N*4];
fk rd[2],bad;
fk times(fk x,fk y)
{
	fk ret;
	ret.a=(x.a*y.a)%MOD;
	ret.b=(x.b*y.a+y.b)%MOD;
	return ret;
}
bool equals(fk x,fk y)
{
	if(x.a==y.a&&x.b==y.b)
	{
		return true;
	}
	return false;
}
void build_tree(ll x,ll l,ll r)
{
	ll i;
	if(l>r)
	{
		segt[x].val=bad;
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	if(l==r)
	{
		segt[x].val=rd[s[l]-'0'];
		return;
	}
	ll mid=(l+r)>>1;
	build_tree((x<<1),l,mid);
	build_tree((x<<1)+1,mid+1,r);
	segt[x].val=times(segt[(x<<1)].val,segt[(x<<1)+1].val);
	return;
}
fk chk(ll x,ll ndl,ll ndr)
{
	if(segt[x].l>=ndl&&segt[x].r<=ndr)
	{
		return segt[x].val;
	}
	if(segt[x].l>ndr||segt[x].r<ndl)
	{
		return bad;
	}
	return times(chk((x<<1),ndl,ndr),chk((x<<1)+1,ndl,ndr));
}
int main(){
	ll i,j,l,r,len,x,y;
	n=rint();
	s=rstr();
	q=rint();
	bad.a=1;
	bad.b=0;
	rd[0].a=87133492;
	rd[0].b=13234139;
	rd[1].a=1000000006;
	rd[1].b=78113365;
	build_tree(1,0,n-1);
	for(i=1;i<=n;i++)
	{
		num[i]=num[i-1]+(s[i-1]=='0');
	}
	while(q--)
	{
		l=rint();
		r=rint();
		l--;
		r--;
		len=rint();
		x=num[l+len]-num[l];
		y=num[r+len]-num[r];
		if(x!=y)
		{
			puts("No");
		}
		else if(x==0)
		{
			puts("Yes");
		}
		else if(equals(chk(1,l,l+len-1),chk(1,r,r+len-1)))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}