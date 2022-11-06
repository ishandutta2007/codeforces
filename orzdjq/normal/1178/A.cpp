#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=105;
int n,a[Maxn];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	int cnt=a[0],tot=a[0];
	vector<int> ans;
	ans.pb(1);
	for (int i=1;i<n;i++){
		if (a[0]>=a[i]*2)cnt+=a[i],ans.pb(i+1);
		tot+=a[i];
	}
	if (cnt*2>tot){
		cout<<ans.size()<<endl;
		for (int i=0;i<ans.size();i++){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}