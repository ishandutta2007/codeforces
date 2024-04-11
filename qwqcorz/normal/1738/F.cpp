#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

int Ask(int x) {
	cout<<"? "<<x<<endl;
	int ret;
	cin>>ret;
	return ret;
}
bool vis[N];
int n,deg[N],col[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>deg[i];
		vis[i]=0;
	}
	int cnt=0;
	while (1) {
		int x=0;
		for (int i=1;i<=n;i++) {
			if (vis[i]) {
				continue;
			}
			if (!x||deg[i]>deg[x]) {
				x=i;
			}
		}
		if (!x) {
			break;
		}
		vis[x]=1;
		col[x]=++cnt;
		for (int t=1;t<=deg[x];t++) {
			int to=Ask(x);
			if (vis[to]) {
				for (int i=1;i<=n;i++) {
					if (col[i]==cnt) {
						col[i]=col[to];
					}
				}
				break;
			} else {
				col[to]=col[x];
				vis[to]=1;
			}
		}
	}
	cout<<"! ";
	for (int i=1;i<=n;i++) {
		cout<<col[i]<<" \n"[i==n];
	}
	cout.flush();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}