#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
ll a[maxn],b[maxn];
int n,m;
int main(){
	cin>>n>>m;
	ll sum = 0;
	for(int i = 0;i < n;++i)scanf("%I64d",&a[i]);
	for(int i = 0;i < m;++i){
		scanf("%I64d",&b[i]);
		sum += b[i];
	}
	sort(a,a+n);
	sort(b,b+m);
	if(a[n-1] > b[0]){
		cout<<-1<<endl;return 0;
	}
	if(a[n-1] < b[0]){
		sum += a[n-1] - b[0];
		sum += a[n-2]*(m-1) + b[0];
		for(int i = n-3;i >= 0;--i) sum+= a[i]*m;
	}
	else for(int i = n-2;i >= 0;--i) sum+= a[i]*m;
	cout<<sum<<endl;
}