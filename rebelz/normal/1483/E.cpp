#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool ask(ll x){
	char s[20];
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='F';
}

void work(){
	ll l=0,r=100000000000001ll,x=1;
	for(int i=1;i<=46;i++){
		bool fl=ask(x);
		if(fl){
			r=x;
			x=0;
			break;
		}
		else{
			l=x;
			x<<=1;
		}
	}
	if(x){
		ll tmp=x/2+22876792454961ll;
		bool fl=ask(tmp);
		if(fl) r=tmp,x-=tmp;
		else l=tmp,x+=tmp;
	}
	if(r==1){
		printf("! 0\n");
		fflush(stdout);
		return;
	}
	while(x<r){
		ask(l);
		x+=l;
	}
	while(l+1<r){
		assert(x>=r);
		if(l+2==r){
			bool fl=ask(l+1);
			if(fl){
				printf("! %lld\n",l);
				fflush(stdout);
				return;
			}
			else{
				printf("! %lld\n",l+1);
				fflush(stdout);
				return;
			}
		}
		ll m1=(2*l+r-1)/3+1,m2=(l+2*r)/3;
		bool fl1=ask(m1);
		if(fl1){
			r=m1,x-=m1;
			while(x<m1) ask(l),x+=l;
		}
		else{
			l=m1,x+=m1;
			bool fl2=ask(m2);
			if(fl2) r=m2,x-=m2;
			else l=m2,x+=m2;
		}
	}
	printf("! %lld\n",l);
	fflush(stdout);
}

int main(){
	int T=readint();
	while(T--) work();
	return 0;
}