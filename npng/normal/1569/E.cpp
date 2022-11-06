#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define fr first
#define sc second
const int Maxn=100000;
const long long dv=998244353;
long long n,m,d,nn=0,nm,pc[Maxn+5],pst[1ll<<4],tmp[1ll<<4];
std::array<ll,1<<4> a0,ca[2];
std::pair<ll,std::array<ll,1<<4> > as[2][Maxn+5];
void bd(ll mk){
	long long i,j,sz,e;
	nm=1ll<<n-1;
	for(i=0;i<nm;i++){
		pst[i]=i;
	}
	for(i=n-1;i;i--){
		sz=nm;
		nm=0;
		for(j=0;j<sz;j+=2){
			e=mk&1;
			mk>>=1;
			ca[0][pst[j+!e]]=(1ll<<i)+1;
			tmp[nm]=pst[j+e];
			nm++;
		}
		for(j=0;j<nm;j++){
			pst[j]=tmp[j];
		}
	}
	ca[0][pst[0]]=2;
	for(i=0;i<1ll<<n-1;i++){
		ca[1][i]=ca[0][i]-(ca[0][i]==2);
	}
}
int main(){
	long long i,ii,mk,p,z;
	scanf("%lld%lld%lld",&n,&m,&d);
	pc[0]=1;
	for(i=1;i<=1ll<<n;i++){
		pc[i]=pc[i-1]*m%dv;
	}
	for(mk=0;mk<1ll<<(1ll<<n-1)-1;mk++){
		bd(mk);
		nn++;
		for(ii=0;ii<2;ii++){
			z=0;
			for(i=0;i<1ll<<n-1;i++){
				z=(z+(i+1)*pc[ca[ii][i]])%dv;
			}
			as[ii][nn]={z,ca[ii]};
		}
	}
	for(ii=0;ii<2;ii++){
		sort(as[ii]+1,as[ii]+nn+1);
	}
	for(mk=0;mk<1ll<<(1ll<<n-1)-1;mk++){
		bd(mk);
		for(ii=0;ii<2;ii++){
			z=0;
			for(i=0;i<1ll<<n-1;i++){
				z=(z+((1ll<<n-1)+i+1)*pc[ca[ii][i]])%dv;
			}
			z=(d+dv-z)%dv;
			p=lower_bound(as[!ii]+1,as[!ii]+nn+1,mp(z,a0))-as[!ii];
			if(p<=nn&&as[!ii][p].fr==z){
				for(i=0;i<1ll<<n-1;i++){
					printf("%lld ",as[!ii][p].sc[i]);
				}
				for(i=0;i<1ll<<n-1;i++){
					printf("%lld%c",ca[ii][i]," \n"[i==(1ll<<n-1)-1]);
				}
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}