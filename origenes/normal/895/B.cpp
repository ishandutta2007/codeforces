#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=102345;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#endif
ll n, x, k, a[maxn], res;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>x>>k;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	for(int i=0; i<n; i++){
		//(k+(a[i]-1)/x)*x<=a[j]<(k+(a[i]-1)/x+1)*x;
		//cout<<(k+(a[i]-1)/x)*x<<' '<<(k+(a[i]-1)/x+1)*x-1<<endl;
		auto it=lower_bound(a, a+n, a[i]);
		auto it1=lower_bound(it, a+n, (k+(a[i]-1)/x)*x);
		auto it2=upper_bound(it, a+n, (k+(a[i]-1)/x+1)*x-1);
		//cout<<i<<' '<<distance(it1, it2)<<'\n'<<endl;
		res+=distance(it1, it2);
	}
	cout<<res<<endl;
	return 0;
}