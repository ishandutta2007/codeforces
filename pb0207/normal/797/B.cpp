
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;


ll n,a[N],s;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
	if(a[i]>0)s+=a[i];
	else a[i]*=-1;
	if(s&1)return 0*printf("%d",s);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	if(a[i]&1)return 0*printf("%d",s-a[i]);
}