#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 15
#define MM 600005
#define ll long long
#define mod 1000000007
int n,m;
int a[MN],b[MN];
int f[1<<MN][3],ans;
int main(){
	scanf("%d%d",&n,&m);
	F2(i,0,n)scanf("%d%d",a+i,b+i),--b[i];
	F2(i,0,n)f[1<<i][b[i]]=1;
	F2(s,3,1<<n){
		if(__builtin_popcount(s)==1)continue;
		F(k,0,2){
			F2(i,0,n)if((s>>i&1)&&b[i]==k){
				f[s][k]=((ll)f[s][k]+f[s^1<<i][0]+f[s^1<<i][1]+f[s^1<<i][2]-f[s^1<<i][k]+mod)%mod;
			}
		}
	}
	F2(s,1,1<<n){
		int q=0;
		F2(i,0,n)if(s>>i&1)q+=a[i];
		if(q==m)ans=((ll)ans+f[s][0]+f[s][1]+f[s][2])%mod;
	}printf("%d\n",ans);
	return 0;
}