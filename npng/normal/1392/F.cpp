#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		s+=a;
	}
	for(int i=0;i<n;i++){
		cout<<i+(s-n*(n-1)/2)/n+(i+1<=(s-n*(n-1)/2)%n)<<" ";
	}
	puts("");
	return 0;
}