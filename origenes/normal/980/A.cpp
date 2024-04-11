#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int cnt1, cnt2;
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>s;
	for(auto it:s){
		if(it=='-') cnt1++;
		else cnt2++;
	}
	if(cnt2==0||cnt1%cnt2==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}