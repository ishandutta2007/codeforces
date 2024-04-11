#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}*/

const int N=2e5;
ll a[N];
int main(){
	ll t;
	cin >> t;
	for (ll i=0; i<t; i++){
		string s,ans="";
		cin >> s;
		ans+=s[0];
		for (ll j=1; j<s.size()-1; j+=2){
			ans+=s[j];
		}
		ans+=s[s.size()-1];
		cout<<ans<<endl;
	}
}