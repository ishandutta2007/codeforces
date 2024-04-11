#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef long long ll;
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
const int mod=1e9+7;
int n,ln1,ln2,ans;
char a[1000001],b[1000001];
int s1,s2,s3,s4,t1,t2,tp,g1,g2;
int fac[1000001],ifac[1000001];
int qwq[2000001];
int p[1000001],s,phi[1000001],pr[1000001],gg,qaq;
bool ok[1000001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
inline int c(int n,int m){
	return n<m||m<0?0:1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1; 
	}
	return tp;
}
inline int gcd(int x,int y){
	while(x%y){
		int tp=y;
		y=x%y;
		x=tp;
	}
	return y;
}
int main(){
	scanf("%s%s%d",a+1,b+1,&n);
	ln1=strlen(a+1),ln2=strlen(b+1);
	fac[0]=1;
	for(int i=1;i<=1000000;i++) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[1000000]=power(fac[1000000],mod-2);
	for(int i=999999;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	if(ln1==ln2){
		for(int i=2;i<=n;i++){
			if(!ok[i]) p[++s]=i,phi[i]=i-1;
			for(int j=1;j<=s&&i*p[j]<=n;j++){
				ok[i*p[j]]=1;
				if(i%p[j]==0){
					phi[i*p[j]]=phi[i]*p[j];
					break;
				}
				phi[i*p[j]]=phi[i]*phi[p[j]];
			}
		}
		for(int i=1;i<=ln1;i++){
			if(a[i]=='?'&&b[i]=='?') s1++;
			else if(a[i]=='?') s2+=(b[i]=='A');
			else if(b[i]=='?') s2-=(a[i]=='A');
			else if(a[i]!=b[i]){
				s2=-10000000;
				break;
			}
		}
		if(s2!=-10000000){
			ans=add(ans,1ll*(power(2,n+1)-2)*(power(2,n+1)-2)%mod*power(2,s1)%mod);
			gg=qwq[s2+1000000]=power(2,s1);
		}
		pr[1]=1;
		for(int i=2;i<=n;i++) pr[i]=(pr[i-1]+2*phi[i])%mod;
		tp=0;
		for(int d=1;d<=n;d++) tp=add(tp,1ll*power(2,d)*pr[n/d]%mod);
		s1=s2=0;
		for(int i=1;i<=ln1;i++){
			if(a[i]=='A') s1++;
			else if(a[i]=='B') s2++;
			else t1++;
			if(b[i]=='A') s3++;
			else if(b[i]=='B') s4++;
			else t2++;
		}
		for(int i=mx(s1,s3);i<=ln1-mx(s2,s4);i++) qaq=add(qaq,1ll*c(t1,i-s1)*c(t2,i-s3)%mod);
		qaq=sub(qaq,gg);
		ans=add(ans,1ll*tp*qaq%mod);
		qwq[s3-s1+1000000]+=qaq;
		qwq[s3-s1+1000000]%=mod;
	}
	s1=s2=t1=t2=0;
	for(int i=1;i<=ln1;i++){
		if(a[i]=='A') s1++;
		else if(a[i]=='B') s2++;
		else t1++;
	}
	for(int i=1;i<=ln2;i++){
		if(b[i]=='A') s1--;
		else if(b[i]=='B') s2--;
		else t2++;
	}
	for(int k=-1000000;k<=1000000;k++){
		tp=c(t1+t2,t1-k);
		tp=sub(tp,qwq[k+1000000]);
		if(!tp) continue;
		g1=s1+k,g2=s2+t1-t2-k;
		if(g1==0&&g2==0) ans=add(ans,1ll*tp*(power(2,n+1)-2)%mod);
		else if(g1>=0&&g2>=0||g1<=0&&g2<=0) continue;
		else g1=abs(g1),g2=abs(g2),ans=add(ans,1ll*tp*(power(2,1+n/(mx(g1,g2)/gcd(g1,g2)))-2)%mod);
	}
	cout<<ans;
}
template <typename _Tp>
	inline _Tp mx(_Tp x,_Tp y){
		return x>y?x:y;
	}
template <typename _Tp>
	inline _Tp mn(_Tp x,_Tp y){
		return x<y?x:y;
	}