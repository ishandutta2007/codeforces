#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=1e9+7;
ll inv[N],jie[N];
void pre(){
	jie[0]=1;inv[0]=inv[1]=1;
	rep(i,2,N){
		int k=mod/i,r=mod%i;
		inv[i]=-k*inv[r]%mod;
		inv[i]+=mod;
	}
	rep(i,1,N)jie[i]=i*jie[i-1]%mod;
	rep(i,2,N)inv[i]=inv[i]*inv[i-1]%mod;
}
int a[N];
ll b[10];
int main(){
	pre();
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]);
	int m=n%4,k=(n-1)/4;
	k<<=1;
	if(m==0){
		rep(i,1,5){
			rep(j,0,k+1){
				b[i]=(b[i]+jie[k]*inv[j]%mod*inv[k-j]%mod*a[i+j*2])%mod;
			}
		}
		ll res=b[1]-b[2]+b[3]-b[4];
		res%=mod;
		if(res<0)res+=mod;
		cout<<res;
		return 0;
	}
	if(m==1){
	//	cout<<"ok\n";
		rep(i,1,2){
			rep(j,0,k+1){
				b[i]=(b[i]+jie[k]*inv[j]%mod*inv[k-j]%mod*a[i+j*2])%mod;
		//		cout<<i+j*2<<' '<<a[i+j*2]<<' '<<jie[k]<<' '<<k<<"check\n"; 
			}
		}
		ll res=b[1];
		res%=mod;
		if(res<0)res+=mod;
		cout<<res;
		return 0;
	}
	if(m==2){
		rep(i,1,3){
			rep(j,0,k+1){
				b[i]=(b[i]+jie[k]*inv[j]%mod*inv[k-j]%mod*a[i+j*2])%mod;
			}
		}
		ll res=b[1]+b[2];
		res%=mod;
		if(res<0)res+=mod;
		cout<<res;
		return 0;
	}
	if(m==3){
		rep(i,1,4){
			rep(j,0,k+1){
				b[i]=(b[i]+jie[k]*inv[j]%mod*inv[k-j]%mod*a[i+j*2])%mod;
			}
		}
		ll res=b[1]+2*b[2]-b[3];
		res%=mod;
		if(res<0)res+=mod;
		cout<<res;
		return 0;
	}
}