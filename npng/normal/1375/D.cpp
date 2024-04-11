#include<bits/stdc++.h>
using namespace std;
const int N=2e3+1;
int T,n,a[N],c[N],A[N],t,v,k;
int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		t=0;
		for(int i=1;;i++)
		{
			v=0;
			for(int j=1;j<n;j++)
				if(a[j]>a[j+1])
					v=1;
			if(!v)
				break;
			memset(c,0,sizeof c);
			for(int j=1;j<=n;j++){
				c[a[j]]=1;
			}
			for(int j=0;j<=n;j++){
				if(!c[j]){
					k=j;
					break;
				}
			}
			if(k<n){
				a[k+1]=k;
				A[++t]=k+1;
				continue;
			}
			for(int j=1;j<=n;j++){
				if(a[j]!=j-1){
					a[j]=k;
					A[++t]=j;
					break;
				}
			}
		}
		cout<<t<<'\n';
		for(int i=1;i<=t;i++)
			cout<<A[i]<<' ';
		cout<<'\n'; 
	}
	return 0;
}