#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define nl '\n'
#define out(x) cout<<x
#define out2(x,y) cout<<x<<' '<<y
#define out3(x,y,z) cout<<x<<' '<<y<<' '<<z
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define drep(i,a,b) for (i=a; i<b; ++i )
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define mp(a,b) make_pair(a,b)
#define setpr(x) cout<<setprecision(x)<<fixed
#define max3(x,y,z) max(x,max(y,z))
#define sz size()
 
 
//-----CONSTANTS-----
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1e9+7;
 
//-----GLOBALS-----
 
//-----SOLUTION-----
bool check(int v, int arr[], int l){
	if (v<0) return 0;
	rep(i,1,10){
		if (v/arr[i]>=l) return 1;
	}
	return 0;
}
void solve(){
	int v;
	cin>>v;
	int arr[10];
	int a2[10];
	int mx=0;
	rep(i,1,10) {
		cin>>arr[i];
		a2[i] = v/arr[i];
		mx= max(mx, a2[i]);
	}
	if (mx==0){cout<<-1;return;}
	int st = 9;
	rep(i,0,mx){
		rev(j,st,0){
			if (check(v-arr[j], arr, mx-i-1)){
				v-=arr[j];
				st=j;
				cout<<j; //cout<<' '<<v<<nl;
				break;
			}
		}
	}
 
}
 
//-----MAIN-----
signed main(){
	IOS;
 
	/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
	
 
	int t=1;
	//cin>>t;
	while(t--) solve();
    
}