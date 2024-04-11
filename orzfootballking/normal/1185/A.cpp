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
int s[4],n=3;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	FOR(i,1,n){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int d;
	cin>>d;
	int t1=s[2]-s[1],t2=s[3]-s[2];
	cout<<max(0,d-t1)+max(0,d-t2);
	RE 0;
}