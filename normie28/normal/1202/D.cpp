#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
 
using namespace std;
	int64_t n,m,i,j,jj,k,minn,maxx,countt=0,counts=0,page,flag,removed=0,temp,op=0,cn[200001],no[200001];

int main()
{
	cn[2]=1;
	for (i=3;i<=200000;i++) cn[i]=cn[i-1]+i-1;
	cin>>n;
	for (i=1;i<=n;i++) {	for (j=1;j<=200000;j++) no[j]=0; flag=0; cin>>k; j=200000; while (k>0) if (k<cn[j]) {no[j]=0; j--;} else {no[j]=k/cn[j]; k%=cn[j]; if (flag==0) {maxx=j; flag=1;} j--;}
	cout<<13; for (j=2;j<=maxx;j++) {cout<<3; for (jj=1;jj<=no[j];jj++) cout<<7;} cout<<endl;
}
}