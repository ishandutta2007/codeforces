#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 50;
int n;
int a[maxn];
int h[maxn*100] = {0};
int main(){
	int n;cin>>n;
	for(int i = 0;i < n;++i) scanf("%d",&a[i]),h[a[i]]++;
	int ans = 0;
	for(int i = 2;i < maxn*100;++i){
		int k = 0;
		for(int j = 0;j < n;++j){
			if(a[j] >= i) continue;
			if(i - a[j] == a[j]){
				k+=h[a[j]]*(h[a[j]] - 1);
			}
			else k+= h[a[j]]*h[i-a[j]];
		}
		ans = max(ans,k);
	}
	ans/=2;
	cout<<ans;
}