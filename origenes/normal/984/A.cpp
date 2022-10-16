#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1234;
int n, a[maxn];
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	cout<<a[(n-1)/2];
	return 0;
}