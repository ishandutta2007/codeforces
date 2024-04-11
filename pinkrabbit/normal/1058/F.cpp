#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define Mod 1000000007
typedef long long LL;

inline void P(int&x,int y){x+=y;if(x>=Mod)x-=Mod;}
int n,q;
int a[200001],w[200001];
LL b1[200001];
int b2[200001];
void Add1(int i,int x){for(;i<=n;i+=i&-i)b1[i]+=x;}
void Add2(int i,int x){for(;i<=n;i+=i&-i)P(b2[i],x);}
LL Qur1(int i){LL A=0;for(;i;i-=i&-i)A+=b1[i];return A;}
int Qur2(int i){int A=0;for(;i;i-=i&-i)P(A,b2[i]);return A;}

int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n) scanf("%d",a+i), a[i]-=i;
	F(i,1,n) scanf("%d",w+i);
	F(i,1,n) Add2(i,(LL)a[i]*w[i]%Mod), Add1(i,w[i]);
	F(i,1,q){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<0){
			Add1(-x,y-w[-x]);
			Add2(-x,(LL)a[-x]*(y-w[-x]+Mod)%Mod);
			w[-x]=y;
		}
		else{
			int l=x,r=y,mid,ans=-1;
			LL Left=Qur1(x-1), Sum=Qur1(r)-Left;
			while(l<=r){
				mid=l+r>>1;
				if(Qur1(mid-1)-Left<<1<=Sum) ans=mid,l=mid+1;
				else r=mid-1;
			}
			printf("%d\n",(((Qur1(ans-1)-Left-Qur1(y)+Qur1(ans))%Mod*a[ans]%Mod-(Qur2(ans-1)-Qur2(x-1))+(Qur2(y)-Qur2(ans)))%Mod+Mod)%Mod);
		}
	}
	return 0;
}