#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
const int N=2e5+9;
string s[25],t[25];
int main()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,n)cin>>s[i];
	rep(i,0,m)cin>>t[i];
	int q;
	cin>>q;
	while(q--){
		int num;
		cin>>num;
		--num;
		int a=num%n,b=num%m;
		cout<<s[a]+t[b]<<endl;
	}
}