#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123456;
ll b[maxn], a, as, n, tot;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		as+=a;
	}
	for(int i=0; i<n; i++)
		cin>>b[i];
	sort(b, b+n);
	tot=b[n-1]+b[n-2];
	if(as>tot) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}