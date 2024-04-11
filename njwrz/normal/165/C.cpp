#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int l[2000009];
int main(){
    ll ans=0,n,i,k,nr=0;
    cin>>k>>s;
    n=s.size();l[nr]=1;
    for(i=0;i<n;i++){
    	nr+=s[i]-'0';
    	if(nr-k>=0)ans=ans+l[nr-k];
    	l[nr]++;
    }
    cout<<ans;
	return 0;
}