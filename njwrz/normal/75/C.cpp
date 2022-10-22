#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	int x,y,t;
	cin>>x>>y;t=__gcd(x,y);
	int cnt=0;
	for(int i=1;i*i<=t;i++){
		if(t%i==0){
			a[++cnt]=i;
			if(i*i!=t)a[++cnt]=t/i;
		}
	}
	sort(a+1,a+cnt+1);
	int n,l,r,zh;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		if(r>=t){
			if(l<=t){
				cout<<t<<'\n';
			}else cout<<-1<<'\n';
			continue;
		}
		zh=upper_bound(a+1,a+cnt+1,r)-a;
		zh--;
		if(a[zh]>=l)cout<<a[zh];
		else cout<<-1;
		cout<<'\n';
	}
	return 0;
}