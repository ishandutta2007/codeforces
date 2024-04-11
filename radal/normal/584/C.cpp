#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
using namespace std; 
const long long int N=1e5;
ll deference (string s,string r){
	ll t=0;
	rep(i,0,s.size()){
		if (s[i] != r[i]){
			t++;
		}
	}
	return t;
}
///set <ll> pos,neg;
//pair <ll,ll> c[N];
//ll a[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	ll n,t,d;
	string s1,s2,ans;
	cin >> n >> t;
	cin >> s1 >> s2;
	rep(i,0,n){
		if (i%2) ans += s1[i];
		else ans += s2[i];
	}
	d=  deference(s1,s2);
	/*if (d/2 + d%2 > t){
		cout << -1 <<endl;
		return 0;
	}*/
	ll k=0,k2=0;
	bool f=0;
	rep (i,0,n){
		if (k >= t && k2 >= t) break;
		if (s1[i] != s2[i]){
			if (d%2 == 1){
				if (max(int(s1[i]),int(s2[i])) < int('z')){
					ans[i] = 'z';
					d--;
					k++;
					k2++;
					continue;
				}
				if (min(int(s1[i]),int(s2[i])) > 'a'){
					ans[i] = 'a';
					d--;
					k++;
					k2++;
					continue;
				}
				ans[i] = 'b';
				d--;
				k++;
				k2++;
				continue;
			}
			if ((!f && k2 < t || k>=t)){
				ans[i] = s1[i];
				k2++;
				f = !f;
				continue;
			}
			else{
				ans[i] = s2[i];
				k++;
				f = !f;
			}
		}
	}
	rep (i,0,n){
		if (k >= t) break;
		if (s1[i] == s2[i]){
			if (s1[i] != 'z'){
				ans[i] = 'z';
			}
			else{
				ans[i] = 'a';
			}
			k++;
			k2++;
		}
	}
	k = deference(s1,ans);
	k2 = deference (s2,ans);
	if (k < t){	
		f=0;
		d = deference(s1,s2)%2;
		rep (i,0,n){
			if (k >= t &&  k2>= t) break;
			if (s1[i] != s2[i]){
				if (!f &&  d%2){
					f=1;
					continue;
				}
				if (max(int(s1[i]),int(s2[i])) < int('z')){
					if (s1[i] == ans[i]) k++;
					else k2++;
					ans[i] = 'z';
					continue;
				}
				if (min(int(s1[i]),int(s2[i])) > 'a'){
					if (s1[i] == ans[i]) k++;
					else k2++;
					ans[i] = 'a';
					continue;
				}
				if (s1[i] == ans[i]) k++;
				else k2++;
				ans[i] = 'b';
				continue;
			}
		}
	}
	if (deference(s1,ans) != deference(s2,ans) || deference(s1,ans) != t){
		//if (n == 1000) cout << deference(s1,ans) << ' '<<deference(s2,ans)<<endl;
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}