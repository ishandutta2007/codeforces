#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l,r;
int main(){
	cin>>n>>k;
	if(n*2-1<k) return puts("0"),0;
	if(k&1ll) l=k>>1,r=l+1;
	else l=(k>>1)-1,r=l+2;
	cout<<min(l,n-r+1)<<endl;
}