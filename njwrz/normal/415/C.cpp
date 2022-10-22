#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	if(n==1){
		if(m!=0){
			cout<<-1;
		}else cout<<1;
		return 0;
	}
	if(n/2>m){
		cout<<-1;return 0;
	}
	int t=m-n/2;
	t++;
	cout<<t<<' '<<t*2<<' ';
	int l=n/2-1,s=2;
	while(l--){
		if(s!=t&&s!=t*2&&(s-1)!=t
			&&(s-1)!=2*t){
			cout<<s-1<<' '<<s<<' ';
		}else l++;
		s+=2;
	}
	if(n%2==1)cout<<1000000000;
	return 0;
}