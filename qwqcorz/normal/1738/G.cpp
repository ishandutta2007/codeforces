#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

int n,k,a[N][N],b[N][N],A[N],B[N];
void work() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		string s;
		cin>>s;
		for (int j=1;j<=n;j++) {
			a[i][j]=s[j-1]=='1';
			b[i][j]=1;
		}
	}
	int p=0;
	for (int i=1;i<=n;i++) {
		A[i]=B[i]=0;
	}
	for (int i=1;i<=n-k+1;i++) {
		while (p<=n&&!a[1+p][1+p]) {
			p++;
		}
		if (p>n) {
			cout<<"NO\n";
			return;
		}
		b[1+p][1+p]=0;
		A[0]=B[0]=p;
		for (int j=1;j<=n-k+1-i;j++) {
			A[j]=max(A[j],A[j-1]);
			while (A[j]<=n-j&&!a[1+j+A[j]][1+A[j]]) {
				A[j]++;
			}
			if (A[j]>n-j) {
				cout<<"NO\n";
				return;
			}
			b[1+j+A[j]][1+A[j]]=0;
		}
		for (int j=1;j<=n-k+1-i;j++) {
			B[j]=max(B[j],B[j-1]);
			while (B[j]<=n-j&&!a[1+B[j]][1+j+B[j]]) {
				B[j]++;
			}
			if (B[j]>n-j) {
				cout<<"NO\n";
				return;
			}
			b[1+B[j]][1+j+B[j]]=0;
		}
		for (int j=1;j<=n-k+1-i;j++) {
			A[j-1]=max(A[j-1],A[j]+1);
			B[j-1]=max(B[j-1],B[j]+1);
		}
		A[n-k+1-i]++,B[n-k+1-i]++;
		p=max(A[0],B[0]);
	}
	cout<<"YES\n";
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cout<<b[i][j];
		}
		cout<<"\n";
	}
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