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

const int N=1000000;
ll k,q;
ll val[6],d[1000005];
const ll pw[6]={1,10,100,1000,10000,100000};

int main(){
	k=readint()-1;
	for(int i=0;i<6;i++) val[i]=readint();
	for(int i=0;i<=N;i++) for(int j=0;j<6;j++) if(i/pw[j]%10%3==0) d[i]+=i/pw[j]%10/3*val[j];
	int sum=0;
	for(int i=0;;i++){
		if(sum+(1<<i)<=3*k){
			for(int j=0;j<6;j++)
				for(int l=N;l>=(1<<i)*pw[j]*3;l--)
					chkmax(d[l],d[l-(1<<i)*pw[j]*3]+(1<<i)*val[j]);
			sum+=1<<i;
		}
		else{
			if(3*k-sum>0){
				for(int j=0;j<6;j++)
					for(int l=N;l>=(3*k-sum)*pw[j]*3;l--)
						chkmax(d[l],d[l-(3*k-sum)*pw[j]*3]+(3*k-sum)*val[j]);
			}
			break;
		}
	}
	q=readint();
	while(q--) printf("%lld\n",d[readint()]);
	return 0;
}