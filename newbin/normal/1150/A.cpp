#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r;
int a[50],b[50];
int main(){
	cin>>n>>m>>r;
	for(int i = 0;i < n;++i) cin>>a[i];
	for(int i = 0;i < m;++i) cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	if(b[m-1] > a[0]){
		int ans = r%a[0] + (r/a[0])*(b[m-1]);
		cout<<ans<<endl;
	}
	else cout<<r<<endl;
}