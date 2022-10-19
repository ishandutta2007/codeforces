#include<bits/stdc++.h>
using namespace std;

int n,qm[2],sum[2];
string s;

int main(){
	cin>>n>>s;
	qm[0]=qm[1]=sum[0]=sum[1]=0;
	for (int i=1;i<=n/2;++i){
		if (s[i-1]=='?'){
			qm[0]++;
		}
		else{
			sum[0]+=s[i-1]-'0';
		}
	}
	for (int i=n/2+1;i<=n;++i){
		if (s[i-1]=='?'){
			qm[1]++;
		}
		else{
			sum[1]+=s[i-1]-'0';
		}
	}
	if (sum[1]==sum[0]+9*(qm[0]-qm[1])/2){
		cout<<"Bicarp";
	}
	else{
		cout<<"Monocarp";
	}
	return 0;
}