#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5; 

int n,a[2][N],b[2][N],tot=0;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=0;i<=1;i++) {
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
			tot+=a[i][j];
		}
	}
	for (int i=0;i<=1;i++) {
		for (int j=1;j<=n;j++) {
			cin>>b[i][j];
			tot-=b[i][j];
		}
	}
	if (tot) {
		cout<<"-1\n";
		return 0;
	}
	ll ans=0;
	int x=0,y=0;
	for (int i=1;i<=n;i++) {
		x+=a[0][i]-b[0][i];
		y+=a[1][i]-b[1][i];
		if (x>0&&y<0) {
			int tmp=min(x,-y);
			x-=tmp,y+=tmp,ans+=tmp;
		}
		if (x<0&&y>0) {
			int tmp=min(-x,y);
			x+=tmp,y-=tmp,ans+=tmp;
		}
		ans+=abs(x)+abs(y);
	}
	cout<<ans<<"\n";
	
	return 0;
}