#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int T,n,m,b[N];
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
struct node{
	int fz,fm;
	friend node operator + (node x,node y){
		node z;
		z.fm=x.fm*y.fm;
		z.fz=y.fm*x.fz+x.fz*y.fm;
		int G=gcd(z.fm,z.fz);
		z.fm/=G;z.fz/=G;
		return z;
	}
	friend bool operator < (node x,node y){
		if(x.fz*y.fm<=y.fz*x.fm)return 1;
		else return 0;
	}
	friend bool operator <= (node x,node y){
		if(x.fz*y.fm<y.fz*x.fm)return 1;
		else return 0;
	}
};
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		node x;
		x.fm=100;x.fz=m;
	//	int G=gcd(x.fm,x.fz);
	//	x.fm/=G;
	//	x.fz/=G;
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		int qz=b[1];
		int ans=0;
		for(int i=2;i<=n;i++){
			node y;
			y.fm=qz;
			y.fz=b[i];
			if(x<=y){
				int l=1;int r=1e12,jl;
				#define mid ((l+r)>>1)
				while(l<=r){
					node u;
					u.fm=qz+mid;u.fz=b[i];
					if(u<x)jl=mid,r=mid-1;
					else l=mid+1;
				}
				ans+=jl;
				qz+=jl;
			}
			qz+=b[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}