// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const double eps=1e-10;
int n,m,L;
pdd a[400005];
multiset<pdd> st;

int main(){
	n=readint(); L=readint();
	int lst=0,x,y; double z;
	for(int i=1;i<=n;i++){
		x=readint(); y=readint(); scanf("%lf",&z);
		if(lst<x) a[++m]=mp(x-lst,0);
		a[++m]=mp(y-x,z);
		lst=y;
	}
	if(lst<L) a[++m]=mp(L-lst,0);
	double num=0,sum=0;
	for(int i=1;i<=m;i++){
		num-=a[i].fi/(a[i].se+2);
		sum+=a[i].fi/(a[i].se+2);
		double rg=0;
		if(fabs(a[i].se)<eps) rg=1e18;
		else rg=a[i].fi/a[i].se+a[i].fi/(a[i].se+2);
		st.insert(mp(1/(a[i].se+1),rg));
		while(num<0){
			pdd tmp=*st.begin(); st.erase(st.begin());
			if(tmp.se+num>0){
				tmp.se+=num,sum-=num*tmp.fi,num=0,st.insert(tmp);
				break;
			}
			else sum+=tmp.se*tmp.fi,num+=tmp.se;
		}
	}
	printf("%.10lf\n",sum);
	return 0;
}