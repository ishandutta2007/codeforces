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
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	char c;
	cin>>n;
	int maxi=0,mini=0;
	FOR(i,1,n){
		cin>>c;
		if(c=='L')mini++;else maxi++;
	} 
	cout<<maxi+mini+1;
	return 0;
}