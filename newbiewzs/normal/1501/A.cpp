#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<cmath>
//#define int long long
using namespace std;
int T,n;
const int N=105;
int a[N],b[N],c[N]; 
int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		int T=0;
		for(int i=1;i<=n;i++){
			T+=a[i]-b[i-1]+c[i];
			if(i==n)break;
			int d=b[i]-T;
			if(d<(b[i]-a[i]+1)/2){
				T+=(b[i]-a[i]+1)/2;
			}
			else{
				T=b[i];
			}
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cout<<T<<endl;
	}
	return 0;
	// using long long?
	// d somet
	// think t d a
}