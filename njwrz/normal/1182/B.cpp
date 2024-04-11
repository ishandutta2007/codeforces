#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
char x;
int a[503][503];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>x;
			if(x=='*')a[i][j]=1,sum++;
			else a[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(!a[i][j])continue;
			int k,ss=1;
			k=i;
			k=j-1;
			bool a1=0,a2=0,a3=0,a4=0;
			while(a[i][k])k--,ss++,a1=1;
			k=j+1;
			while(a[i][k])k++,ss++,a2=1;
			k=i-1;
			while(a[k][j])k--,ss++,a3=1;
			k=i+1;
			while(a[k][j])k++,ss++,a4=1;
			if(ss==sum&&a1&&a2&&a3&&a4) {
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}