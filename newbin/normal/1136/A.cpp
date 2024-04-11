#include<iostream>
using namespace std;
const int maxn = 150;
int l[maxn],r[maxn];
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;++i) cin>>l[i]>>r[i];
	int k;cin>>k;
	int ans = 0;
	for(int i = 0;i < n;++i){
		if(k <= r[i]) {
			ans = i;break;
		}
	}
	ans = n - ans;
	cout<<ans;
}