#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=200000;
typedef long long ll;
int n,k;
int a[Maxn+5],w[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&w[i]);
		}
		sort(a+1,a+1+n);
		sort(w+1,w+1+k,cmp);
		ll ans=0;
		int l=1,r=n;
		int tmp=k;
		while(w[tmp]<=2){
			int i=tmp;
			if(w[i]==1){
				ans+=a[r]*2;
				r--;
			}
			if(w[i]==2){
				ans+=a[r];
				r--;
				ans+=a[r];
				r--;
			}
			tmp--;
		}
		for(int i=1;i<=tmp;i++){
			ans+=a[r];
			r--;
			ans+=a[l];
			l+=w[i]-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}