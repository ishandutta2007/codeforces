#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123456;
ll a[maxn], b[maxn], m, n;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	ll p1=1, p2=1, cur1=a[0], cur2=b[0], ans=0;
	do{
		if(cur1==cur2){
			cur1=a[p1++];
			cur2=b[p2++];
			ans++;
		}else if(cur1<cur2){
			cur1+=a[p1++];
		}else{
			cur2+=b[p2++];
		}
	}while(p1<=n||p2<=m);
	cout<<ans<<endl;
	return 0;
}