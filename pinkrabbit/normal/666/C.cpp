// By pkrabit
#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;typedef long long ll;

const int Mod=1000000007;
int m,n,k,opt;
char str[100005];
bool vis[100005];
int frc[100005]={1,1},inv[100005]={1,1},Pow[100005]={1};
vector<int> f[100005];

inline int C(int N,int K){if(K<0||K>N)return 0; return (ll)frc[N]*inv[K]%Mod*inv[N-K]%Mod;}
inline int calc(int N,int K){return (ll)C(N,K)*Pow[N-K]%Mod;}

int main(){
	F(i,2,100000) frc[i]=(ll)frc[i-1]*i%Mod;
	F(i,2,100000) inv[i]=(ll)(Mod-Mod/i)*inv[Mod%i]%Mod;
	F(i,2,100000) inv[i]=(ll)inv[i-1]*inv[i]%Mod;
	F(i,1,100000) Pow[i]=Pow[i-1]*25ll%Mod;
	scanf("%d",&m);
	scanf("%s",str); k=strlen(str);
	F(i,1,m){
		scanf("%d",&opt);
		if(opt==1) scanf("%s",str), k=strlen(str);
		else{
			if(!vis[k]){
				vis[k]=1;
				f[k].push_back(0);
				F(j,1,100000){
					f[k].push_back((calc(j-1,k-1)+26ll*f[k][j-1]%Mod)%Mod);
				}
			}
			scanf("%d",&n);
			printf("%d\n",f[k][n]);
		}
	}
	return 0;
}