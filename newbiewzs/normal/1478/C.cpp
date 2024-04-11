#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=2e5+5;
int a[N],n,m;
int pd[N],jl[N];
int cmp(int x,int y){
	return x>y;
}
map<long long,long long>ma;
signed main(){
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		map<long long,long long>ma;
		for(int i=1;i<=2*n;i++){
			scanf("%lld",&a[i]);
			ma[a[i]]++;
		}
		bool flag=0;
		for(int i=1;i<=2*n;i++){
			if(ma[a[i]]%2==1 or ma[a[i]]>2){
				flag=1;
			}
		}
		ma.clear();
		if(flag)puts("NO");
		else{			
			sort(a+1,a+2*n,cmp);
			int js=0,zs=0;
			for(int i=1;i<=n;i++){
				if((a[(i-1)*2+1]-zs)%(2*n-(i-1)*2)==0 and (zs<(a[(i-1)*2+1]))){
					zs+=(a[(i-1)*2+1]-zs)/(2*n-(i-1)*2)*2;
				}
				else flag=1;
			}
			if(flag)puts("NO");
			else puts("YES");
		}
	}
	return 0;
} 
/*
1
4
40 56 48 40 80 56 80 48
*/