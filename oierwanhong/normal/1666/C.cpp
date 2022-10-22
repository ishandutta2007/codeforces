#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
//#define int long long 
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
  
#define maxn 400005
#define inf 0x3f3f3f3f

pii a[maxn],aa[233];
pii b[233],c[233];
int len;

bool cmp(pii o1,pii o2){
	return o1.second<o2.se;
}

signed main()
{
	For(i,1,3)a[i].fi=read(),a[i].se=read(),aa[i]=a[i];
	sort(a+1,a+3+1);
	sort(aa+1,aa+3+1,cmp);
	if(a[1].fi<a[3].fi){
		++len;
		b[len]=mkp(a[1].fi,aa[2].se);
		c[len]=mkp(a[3].fi,aa[2].se);
	}
	For(i,1,3)
		if(a[i].se!=aa[2].se){
			++len;
			b[len]=mkp(a[i].fi,a[i].se);
			c[len]=mkp(a[i].fi,aa[2].se);
		}
	cout<<len<<endl;
	For(i,1,len){
		cout<<b[i].fi<<' '<<b[i].se<<" "<<c[i].fi<<" "<<c[i].se<<endl;
	}
	return 0;
}