#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 
int main() {
	ll t,ans1=0,ans2=0,m=0;
	vector <ll> ve;
	string s;
	cin >> t;
	ll a[t];
	rep (i,0,t){
		cin >> a[i];
	}
	cin >> s;
	rep (i,0,t){
		if (s[i] == '1'){
			ans1+=a[i];
			if (m-a[i]>0){
				ve.push_back(m-a[i]);
			}
		}
		else{
			m+=a[i];
		}
	}
	sort(ve.begin(),ve.end());
	if (ve.size()) cout<<ans1+ve[ve.size()-1];
	else cout << ans1;
	
}