#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int maxn=12345;
ll a[maxn], N, n, buff[maxn], cnt1;
ll gcd(ll a, ll b){
	return !b?a:gcd(b, a%b);
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
	}
	if(cnt1){
		cout<<n-cnt1<<endl;
		return 0;
	}
	N=n-1;
	while(cnt1<n){
		cnt1++;
		for(int i=0; i<N; i++){
			buff[i]=gcd(a[i], a[i+1]);
			if(buff[i]==1){
				cout<<n-1+cnt1<<endl;
				return 0;
			}
		}
		memcpy(a, buff, N*sizeof(ll));
		N--;
	}
	cout<<-1<<endl;
	return 0;
}