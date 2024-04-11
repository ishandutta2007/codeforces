#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a,b,c;cin>>a>>b>>c;
	if (a>b) swap(a,b);
	if (b>c) swap(b,c);
	if (a>b) swap(a,b);
	int res=0;
	res+=b-a;
	c-=b-a;
	b=a;
	int cur=min(c,a+b);
    res+=cur;

	c-=cur;
	a-=cur/2;
	b-=cur-cur/2;
 //   cout<<a<<" "<<b<<" "<<c<<" "<<res<<endl;
	res+=min(a,b);
	cout<<res<<endl;
}
int main(){
	int tt;cin>>tt;
	while(tt--){
		solve();
	}
	return 0;
}