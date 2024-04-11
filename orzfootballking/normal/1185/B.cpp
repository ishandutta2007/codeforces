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
char c[1000005],c2[1000005];int t[1000005],t2[1000005];
void solve(){
	string a,b;
	cin>>a>>b;
	int l1,l2;l1=l2=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=c[l1]){
			l1++;
			c[l1]=a[i];t[l1]=1;
		}else t[l1]++;
	}
	for(int i=0;i<b.size();i++){
		if(b[i]!=c[l2]){
			l2++;
			c2[l2]=b[i];t2[l2]=1;
		}else t2[l2]++;
	}
	if(l1!=l2){
		cout<<"NO\n";RE;
	}
	FOR(i,1,l1){
		if(c[i]!=c2[i]||t[i]>t2[i]){
			cout<<"NO\n";RE; 
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}