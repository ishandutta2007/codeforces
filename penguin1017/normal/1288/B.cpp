#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define lb(x) ((x)&(-x))
using namespace std;
const int N=2e6+9;
vi g[N];
int n,t;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		b++;
		int cnt=0;
		while(b){
			++cnt;
			b/=10;
		}
		--cnt;
		cout<<(ll)a*cnt<<endl;
	}
}