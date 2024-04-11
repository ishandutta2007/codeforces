#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std; 
const long long int N=1e6;
ll b[N],l[N],r[N],e[N];
pair <ll,ll> a[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	ll n,m=0,j=0;
	cin >> n;
	rep (i,0,n){
		cin >> b[i];
		if (b[i] > m){
			m = b[i];
			j = i;
		}
	}
	rep (i,0,n){
		a[i] = mp(b[(j+i)%n],i);
	}
	stack <pair<ll,ll> > st;
	rep (i,0,n){
		bool f =0;
		if (st.empty()){
			st.push(a[i]);
			l[i] = -1;
			continue;
		}
		while (!st.empty() && st.top().X <= a[i].X){
			if (st.top().X == a[i].X && !f){
				e[i] = e[st.top().Y]+1;
				f = 1;
			}
			st.pop();
		}
		if (st.empty()){
			l[i] = -1;
			st.push(a[i]);
			continue;
		}
		l[i] = st.top().Y;
		st.push(a[i]);
	}
	stack <pair<ll,ll> > st2;
	repr (i,n-1,0){
		if (st2.empty()){
			st2.push(a[i]);
			r[i] = -1;
			continue;
		}
		while (!st2.empty() && st2.top().X <= a[i].X){

			st2.pop();
		}
		if (st2.empty()){
			r[i] = -1;
			st2.push(a[i]);
			continue;
		}
		r[i] = st2.top().Y;
		st2.push(a[i]);
	}
	ll ans = 0;
	rep(i,0,n){
		ans += e[i];
		if (r[i] == l[i] && r[i] == -1) continue;
		if (l[i] != -1) ans++;
		if (r[i] != -1) ans++;
		//if (r[i] == l[i]) ans--;
		if (r[i] == -1 && l[i] != 0) {
			ans++;
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
	
	
}