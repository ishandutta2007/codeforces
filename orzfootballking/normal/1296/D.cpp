#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a,b,h;
V<int> v;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
	cin>>n>>a>>b>>k;
	int ans=0;
	FOR(i,1,n){
		cin>>h;
		h%=(a+b);
		if(!h){
			v.PB(b);
		}else if(h<=a){
			ans++;
		}else{
			v.PB(h-a);
		}
	}
	sort(ALL(v));
	for(int i=0;i<v.size();i++){
		int c=v[i]/a+(v[i]%a!=0);
		if(c>k){
			break;
		}else{
			k-=c;
			ans++;
		}
	}
	cout<<ans;
	RE 0;
}