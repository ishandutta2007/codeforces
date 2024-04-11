#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 1e4 + 50;
int a[maxn];
int main(){
	int n;cin>>n;
	for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
	int ans = 0;
	int l = 0;
	while(l < n){
		l++;
		int mx = a[l];
		while(l < mx && l < n){
			l++;mx = max(mx,a[l]);
		}
		ans++;
	}
	cout<<ans;
}