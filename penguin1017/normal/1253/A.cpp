#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e5+9;
int a[N],b[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,0,n)scanf("%d",&a[i]);
		rep(i,0,n)scanf("%d",&b[i]);
		int d=0,flag=0;
		rep(i,0,n){
			if(a[i]>b[i]){
				flag=2;
				break;
			}
			if(!d){
				if(a[i]==b[i])continue;
				if(flag){
					flag=2;
					break;
				}
				else {
					flag=1;
					d=a[i]-b[i];
					continue;
				}
			}
			if(d){
				if(a[i]-b[i]==0){
					d=0;
					continue;
				}
				if(a[i]-b[i]==d)continue;
				flag=2;
				break;
			}
		}
		if(flag<2)printf("YES\n");
		else printf("NO\n");
	}
}