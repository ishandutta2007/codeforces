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
		int n,d;
		cin>>n>>d;
		int mini=d;
		rep(i,1,d+1){
			int last=d/(i+1);
			if(d%(i+1))++last;
			mini=min(mini,i+last);
			if(last<=i)break;
		}
		if(mini<=n)printf("YES\n");
		else cout<<"NO\n"; 
	}
}