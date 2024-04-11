#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

long double h,m,s,t1,t2,a[10];

int main(){
	h=readint(); m=readint(); s=readint(); t1=readint(); t2=readint();
	if(h==12) h=0;
	h+=1.0*m/60+1.0*s/60/60;
	m+=1.0*s/60;
	m/=5;
	s/=5;
	a[1]=h,a[2]=m,a[3]=s;
	sort(a+1,a+4);
	a[0]=0,a[4]=12;
	int pl1=0,pl2=0;
	for(int i=0;i<4;i++) if(a[i]<=t1&&t1<=a[i+1]) pl1=i;
	for(int i=0;i<4;i++) if(a[i]<=t2&&t2<=a[i+1]) pl2=i;
	if(pl1==pl2||(pl1==0&&pl2==3)||(pl1==3&&pl2==0)) printf("YES\n");
	else if(pl1!=pl2) printf("NO\n");
	return 0;
}