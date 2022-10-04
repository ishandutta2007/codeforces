#include <bits/stdc++.h>
using namespace std;
using TM=array<uint64_t,10>;
uint64_t inv5=14757395258967641293ULL;
TM mul(const TM& a,const TM& b){
	TM ret={};
	for(int i=0;i<10;i++)for(int j=0;j<10;j++){
		ret[(i+j)%10]+=a[i]*b[j];
	}
	return ret;
}
TM a[100000];
TM pow2(TM a,int n){
	if(!n){
		TM ret={};
		ret[0]=1;
		return ret;
	}
	TM t=pow2(a,n/2);
	t=mul(t,t);
	if(n&1)t=mul(t,a);
	return t;
}
void fft(bool inv=false){
	int sh=inv?9:1;
	for(int i=1;i<100000;i*=10)for(int j=0;j<100000;j+=10*i)for(int k=j;k<j+i;k++){
		TM b[10]={};
		for(int s=0;s<10;s++)for(int t=0;t<10;t++)for(int r=0;r<10;r++)b[s][(r+s*t*sh)%10]+=a[k+t*i][r];
		for(int s=0;s<10;s++)a[k+s*i]=b[s];
	}
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		a[x][0]++;
	}
	fft();
	for(int i=0;i<100000;i++)a[i]=pow2(a[i],n);
	fft(true);
	for(int i=0;i<n;i++){
		uint64_t res=a[i][0]+a[i][1]-a[i][2]-a[i][5];
		res/=32;
		for(int j=0;j<5;j++)res*=inv5;
		printf("%llu\n",res%(1ULL<<58));
	}
}