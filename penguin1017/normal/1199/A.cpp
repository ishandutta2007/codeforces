#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define N (int)1e6+9
using namespace std;
int a[N],L[N],R[N];
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,1,n+1){
		int flag=1;
		rep(j,max(1,i-x),i)if(a[j]<a[i])flag=0;
		rep(j,i+1,min(i+y+1,n+1))if(a[j]<a[i])flag=0;
	//	if(i==3)cout<<flag<<"??\n";
		if(flag){
			cout<<i;
			return 0;
		}
	}
}