#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,a[55];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int l,r;
	l=r=0;
	bool f=0;
	V<V<int> > ans;
	if(n&1){
	for(int i=n;i>=1;i--){
		f^=1;swap(l,r);
		if(i!=n)r++;
		V<int> v;
		V<V<int> > now;
		V<int> len;
		int t=0;
		if(f){
			FOR(j,1,n){
				if(a[j]==n-(n-i)/2){
					t=j;
					break;
				}
			}
		}else{
			int mid=n/2;
			FOR(j,1,n){
				if(a[j]==mid-(n-i)/2){
					t=j;
					break;
				}
			}
		}
		if(l)len.PB(l);
		if(t-l)len.PB(t-l);if(n-r-t)len.PB(n-r-t);
		if(r)len.PB(r);	
		int lst=0;
		for(auto u:len){
			V<int> tv;
			FOR(j,lst+1,lst+u){
				tv.PB(a[j]);
			}
			now.PB(tv);
			lst+=u;
		}
		reverse(ALL(now));
		lst=0;
		for(auto u:now){
			FOR(j,lst+1,lst+u.size())a[j]=u[j-lst-1];
			lst+=u.size();
		}
		if(len.size()==1)continue;
		ans.PB(len);
	}
	}else{
	for(int i=n;i>=1;i--){
		f^=1;swap(l,r);
		if(i!=n)l++;
		V<int> v;
		V<V<int> > now;
		V<int> len;
		int t=0;
		if(f){
			int mid=n/2+1;
			FOR(j,1,n){
				if(a[j]==mid+(n-i)/2){
					t=j;
					break;
				}
			}
		}else{
			FOR(j,1,n){
				if(a[j]==(n-i)/2+1){
					t=j;
					break;
				}
			}
		}
		if(l)len.PB(l);
		if(t-l-1)len.PB(t-l-1);if(n-r-t+1)len.PB(n-r-t+1);
		if(r)len.PB(r);	
		int lst=0;
		for(auto u:len){
			V<int> tv;
			FOR(j,lst+1,lst+u){
				tv.PB(a[j]);
			}
			now.PB(tv);
			lst+=u;
		}
		reverse(ALL(now));
		lst=0;
		for(auto u:now){
			FOR(j,lst+1,lst+u.size())a[j]=u[j-lst-1];
			lst+=u.size();
		}
		if(len.size()==1)continue;
		ans.PB(len);
	}
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans){
		cout<<u.size()<<' ';
		for(auto k:u){
			cout<<k<<' ';
		}
		cout<<'\n';
	}
	RE 0;
}