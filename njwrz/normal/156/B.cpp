#include<string.h>
#include<iostream>
using namespace std;
int a[100005],b[100005],f[100005],d[100005];
char c[100005];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,t=0,q=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		if(c[i]=='-') {
			cin>>d[i];
			t++;
			b[d[i]]++;
		} else {
			cin>>d[i];
			a[d[i]]++;
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(a[i]+t-b[i]==m) {
			f[i]=1;ans++;
		}
	}
	for(int i=1; i<=n; i++) {
		if(c[i]=='-') {
			if(f[d[i]]) {
				if(ans>1){
					cout<<"Not defined\n";
				}else cout<<"Lie\n";
			} else{
				cout<<"Truth\n";
			}
		} else {
			if(f[d[i]]) {
				if(ans>1){
					cout<<"Not defined\n";
				}else cout<<"Truth\n";
			} else{
				cout<<"Lie\n";
			}
		}
	}
	return 0;
}