#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=61234;
ll n, s, a[maxn], cur;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	s=(n+1)*n/2;
	if(s&1){
		cout<<1<<endl;
		s/=2;
		for(ll i=n; i>0; i--){
			if(!s) break;
			if(i>s) continue;
			s-=i;
			a[cur++]=i;
		}
		cout<<cur<<' ';
		for(int i=0; i<cur; i++)
			cout<<a[i]<<' ';
	}else{
		cout<<0<<endl;
		s/=2;
		for(ll i=n; i>0; i--){
			if(!s) break;
			if(i>s) continue;
			s-=i;
			a[cur++]=i;
		}
		cout<<cur<<' ';
		for(int i=0; i<cur; i++)
			cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}