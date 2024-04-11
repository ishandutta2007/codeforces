#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=35*N;
const ll lim=(((ll)1)<<32)-1;
bool white[M],black[M],bx[M],wx[M];
int ls[M],rs[M],tsz,root;
void Set(int &c, ll ss, ll se, ll qs, ll qe, bool t)
{
	if(qs>qe || ss>qe || qs>se) return;
	if(!c) c=++tsz;
	if(t) black[c]=1;
	else white[c]=1;
	if(qs<=ss && qe>=se)
	{
		if(t) bx[c]=1;
		else wx[c]=1;
		return;
	}
	ll mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,t);
	Set(rs[c],mid+1,se,qs,qe,t);
}
bool ok=1;
vector<pair<ll,ll> > ans;
void Solve(int c, ll ss, ll se, bool b, bool w, int dep)
{
	b|=bx[c],w|=wx[c];
	//printf("(%lld %lld) b:%i w:%i\n",ss,se,b|black[c],w|white[c]);
	if(!b && !black[c] && !w && !white[c]) return;
	if((black[c] || b) && (white[c] || w))
	{
		if(ss==se) ok=0;
		else
		{
			ll mid=ss+se>>1;
			Solve(ls[c],ss,mid,b,w,dep-1);
			Solve(rs[c],mid+1,se,b,w,dep-1);
		}
	}
	else if(white[c] || w) return;
	else if(black[c] || b)
	{
		ans.push_back(make_pair(ss,dep));
		return;
	}
}
int main()
{
	int n,i;char s[20];
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		bool t;
		if(s[0]=='-') t=1;
		else t=0;
		int j=0;
		int a=0,b=0,c=0,d=0,x=32;
		for(j++;s[j]!='.';j++) a*=10,a+=s[j]-'0';
		for(j++;s[j]!='.';j++) b*=10,b+=s[j]-'0';
		for(j++;s[j]!='.';j++) c*=10,c+=s[j]-'0';
		for(j++;s[j]!='/' && s[j]!=0;j++) d*=10,d+=s[j]-'0';
		if(s[j]=='/') for(j++;s[j]!=0;j++) x*=10,x+=s[j]-'0';
		x=32-x;
		ll num=(ll)((ll)a<<24)+((ll)b<<16)+((ll)c<<8)+d;
		ll l=(num>>x)<<x;
		ll r=l+(1<<x)-1;
		//printf("num: %lld a:%i b:%i c:%i d:%i (%lld %lld)\n",num,a,b,c,d,l,r);
		Set(root,0,lim,l,r,t);
	}
	Solve(root,0,lim,0,0,32);
	if(!ok) printf("-1\n");
	else
	{
		printf("%i\n",ans.size());
		for(auto p:ans)
		{
			ll num=p.first;
			int a,b,c,d;
			d=num%256;num/=256;
			c=num%256;num/=256;
			b=num%256;num/=256;
			a=num%256;num/=256;
			printf("%i.%i.%i.%i",a,b,c,d);
			if(p.second!=0) printf("/%i\n",32-p.second);
			else printf("\n");
			//printf("%lld %lld\n",p.first,p.first+((ll)1<<p.second)-1);
		}
	}
	return 0;
}