#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,t,a[100005];
	cin>>n>>m;
	t=(m+1)*m/2;
	if(n<t){
		cout<<"NO";return 0;
	}
	for(int i=1;i<=m;i++)a[i]=i;
	n-=t;
	for(int i=1;i<=m;i++)a[i]+=n/m;
	n%=m;
	int l=m;
	while(n){
		if(a[l]<(a[l-1]<<1)){
			a[l]++;l--;n--;
		}else {
			if(l==m){
				cout<<"NO";return 0;
			}else l=m;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=m;i++)cout<<a[i]<<' ';
	return 0;
}