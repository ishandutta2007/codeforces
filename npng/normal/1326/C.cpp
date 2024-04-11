#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=200000;
const int Mod=998244353;
typedef long long ll;
int pos[Maxn+5];
int n,k;
int lim[Maxn+5];
int a[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	ll ans_1=0;
	int ans_2=1;
	for(int i=n;i>=n-k+1;i--){
		lim[n-i+1]=pos[i];
		ans_1+=i;
	}
	sort(lim+1,lim+1+k);
	for(int i=1;i<k;i++){
		ans_2=1ll*ans_2*(lim[i+1]-lim[i])%Mod;
	}
	cout<<ans_1<<' '<<ans_2<<endl;
	return 0;
}