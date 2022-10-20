#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,a[N],pre[N];
bool check(int n) {
	for (int i=1,now=0;i<=n;i++) {
		if ((now+=a[i])<0) {
			return 0;
		}
	}
	return 1;
}
void work() {
	string s;
	cin>>n>>s;
	for (int i=1;i<=n+n;i++) {
		a[i]=s[i-1]=='('?1:-1;
	}
	if (check(n+n)) {
		cout<<"0\n";
		return;
	}
	int l=-1,r=-1;
	for (int i=1;i<=n+n;i++) {
		pre[i]=pre[i-1]+a[i];
		if (pre[i]<0) {
			if (l<0) {
				l=i;
			}
			r=i;
		}
	}
	int L=max_element(pre,pre+l)-pre+1;
	int R=max_element(pre+r,pre+n+n+1)-pre;
	reverse(a+L,a+R+1);
	if (check(n+n)) {
		cout<<"1\n"<<L<<' '<<R<<"\n";
		return;
	}
	int M=max_element(pre+1,pre+n+n+1)-pre;
	cout<<"2\n"<<1<<' '<<M<<"\n"<<M+1<<' '<<n+n<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}