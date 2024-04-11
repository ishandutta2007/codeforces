#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct num{
	int index, no;
	bool operator < (const num& rhs){
		return no<rhs.no;
	}
};
const int maxn=123;
num a[maxn];
int b[maxn];
int n;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i].no;
		a[i].index=i;
	}
	sort(a, a+n);
	b[a[0].index]=a[n-1].no;
	for(int i=1; i<n; i++)
		b[a[i].index]=a[i-1].no;
	for(int i=0; i<n; i++)
		cout<<b[i]<<' ';
	cout<<endl;
	return 0;
}