#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, cnt1, cnt2, res, n;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>a;
		if(a==1) cnt1++;
		else cnt2++;
	}
	if(cnt2>cnt1) res=cnt1;
	else res=cnt2+(cnt1-cnt2)/3;
	cout<<res<<endl;
	return 0;
}