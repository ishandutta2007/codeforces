#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

typedef long double ld;

const ld eps=1e-8;
int n;
ld ans;
ld x[100005],y[100005];

bool check(ld k){
	ld maxa=-1e15,mina=1e15;
	for(int i=1;i<=n;i++)
		if(2*k-y[i]<0)
			return false;
	for(int i=1;i<=n;i++)
		maxa=max(maxa,x[i]-sqrt(2*k*y[i]-y[i]*y[i])),mina=min(mina,x[i]+sqrt(2*k*y[i]-y[i]*y[i]));
	if(maxa<=mina)
		return true;
	return false;
}

int main(){
	cin>>n;
	bool flagx=false,flagy=false;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(y[i]>0)
			flagx=true;
		if(y[i]<0)
			flagy=true;
	}
	if(flagx&&flagy){
		cout<<-1<<endl;
		return 0;
	}
	if(flagy)
		for(int i=1;i<=n;i++)
			y[i]*=-1;
	ld l=0,r=1e14;
	for(int i=1;i<=100;i++){
		ld mid=(l+r)/2;
		if(check(mid))
			ans=mid,r=mid-eps;
		else
			l=mid+eps;
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}