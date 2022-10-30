#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 
int main() {
	ll t;
	cin >> t;
	rep (i,0,t){
		ll n;
		string s;
		stack <char> st;
		cin >> n;
		cin >> s;
		ll k;
		repr (j,n-1,0){
			if (s[j]=='0'){
				k=j;
				break;
			}
		}
		rep (j,0,n){
			if (st.empty()){
				st.push(s[j]);
				continue;
			}
			if (j!=k and s[j] == '0' && st.top() == '1'){
				continue;
			}
			if (s[j] == '0' && st.top() == '1' && j==k){
				while (!st.empty() && st.top() == '1'){
					st.pop();
				}
			}
			st.push(s[j]);
		}
		string ans="";
		while(!st.empty()){
			ans+=st.top();
			st.pop();
		}
		reverse(ans.begin(),ans.end());
		cout<< ans << endl;
	}
}