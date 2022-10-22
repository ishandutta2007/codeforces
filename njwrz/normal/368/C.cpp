#include <bits/stdc++.h>
#define ms(a,b,c) min(a,min(b,c))
#define mt(a,b,c) max(a,max(b,c))
using namespace std;
int a[3][100005],t[3];
int main(){
	string s;
	cin>>s;
	int n,l,r;
	for(int i=0;i<s.size();i++){
		if(s[i]>='x'){
			a[s[i]-'x'][i+1]++;
		}
		for(int j=0;j<3;j++){
			a[j][i+1]+=a[j][i];
		}
	}
	cin>>n;
	int zh;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		if(r-l<2){
			cout<<"YES\n";continue;
		}
		zh=0;
		for(int j=0;j<3;j++){
			t[j]=a[j][r]-a[j][l-1];zh+=t[j];
		}
		if(zh!=r-l+1||mt(t[0],t[1],t[2])
			-ms(t[0],t[1],t[2])>1){
			cout<<"NO\n";
		}else cout<<"YES\n";
	}
	return 0;
}