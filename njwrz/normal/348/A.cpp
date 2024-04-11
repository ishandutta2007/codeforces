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
ll x,n,maxi,s;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    FOR(i,1,n){
    	cin>>x;
    	maxi=max(maxi,x);
    	s=s+x; 
	} 
	s=s/(n-1)+(s%(n-1)!=0);
	cout<<max(s,maxi);
	return 0;
}