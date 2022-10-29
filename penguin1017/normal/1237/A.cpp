#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int N=(int)2e4;
int a[N],pos[N];
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	rep(i,0,n){
		scanf("%d",&a[i]);
		if(a[i]&1){
			pos[i]=1;
			if(a[i]>0)a[i]/=2;
			else a[i]=a[i]/2-1;
			sum++;
		}
		else{
			a[i]/=2;
		}
	}
	sum/=2;
	rep(i,0,n){
		if(pos[i]&&sum){
			sum--;
			a[i]++;
		}
	}
	rep(i,0,n)printf("%d\n",a[i]);
 }