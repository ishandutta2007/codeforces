#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime> // lgv
using namespace std;
#define LL long long
LL n; int k;
bool Train(LL l,LL r){
	printf("%lld %lld\n",l,r);
	fflush(stdout);
	char str[5];
	scanf("%s",str);
	return *str=='Y';
}
int main(){
	srand(time(0));
	scanf("%lld%d",&n,&k);
	LL l=1, r=n;
	for(;;){
		LL len=r-l+1;
		LL w=(len+1)/2-k;
		if(w<=2){
			int RP=rand()%(len+k+k);
			if(Train(max(1ll,min(n,l-k+RP)),max(1ll,min(n,l-k+RP)))) exit(0);
			else l=max(l-k,1ll), r=min(r+k,n);
		}
		else{
			LL nl=max(l-k,1ll), nr=max(r-k-w,1ll);
			if(Train(nl,nr)) l=nl, r=nr;
			else l=min(nr+1,n), r=min(r+k,n);
		}
	}
	return 0;
}