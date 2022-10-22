#include<bits/stdc++.h>
using namespace std;
char c[1001];
int main(){
	long long t,n,l,r;
	cin>>t;
	while(t--){
		cin>>n;getchar();
		gets(c);
		l=0;r=n-1;
		while(l<=r){
			if(c[l]==c[r]){
				l++;r--;continue;
			}
			if(c[l]<c[r])c[l]++;
			else if(c[l]>c[r])c[l]--;
			if(c[l]==c[r]){
				cout<<"NO"<<endl;break;
			}
			if(c[l]<c[r])c[r]--;
			else if(c[l]>c[r])c[r]++;
			if(c[l]!=c[r]){
				cout<<"NO"<<endl;break;
			}
			else{
				l++;r--;
			}
		}
		if(l>r)cout<<"YES"<<endl;
	}
	return 0;
}