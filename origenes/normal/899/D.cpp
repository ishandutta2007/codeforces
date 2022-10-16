#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=25;
ll n, a[maxn], rec, res;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	a[0]=0;
	a[1]=5;
	for(int i=2; i<15; i++) a[i]=a[i-1]*10LL;
	cin>>n;
	for(int i=14; i>=0; i--) if(n>=a[i]){
			rec=i;
			break;
		}
	if(rec==0){
		switch(n){
			case 2:{cout<<1<<endl; break;}
			case 3:{cout<<3<<endl; break;}
			default:{cout<<6<<endl; break;}
		}
		return 0;
	}
	ll b=1, offset=0;
	for(int i=0; i<rec; i++){
		offset*=10;
		offset+=9;
		b*=10;
	}
	for(int i=0; i<9; i++){
		ll num=i*b+offset;
		if(num/2+1>n) break;
		ll st=num/2+1;
		ll ed=min(num-1, n);
		res+=ed-st+1;
	}
	cout<<res<<endl;
	return 0;
}