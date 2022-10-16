#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
//const int maxn=;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int l, r, a;
	cin>>l>>r>>a;
	if(l>r) swap(l, r);
	if(r-l>=a){
		cout<<2*(l+a)<<endl;
	}else{
		if((l+r+a)&1) cout<<l+r+a-1<<endl;
		else cout<<l+r+a<<endl;
	}
	return 0;
}