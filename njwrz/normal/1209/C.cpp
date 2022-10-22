#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	int t;cin>>t;
	for(int k=0;k<t;k++){
		int l;
		cin>>l;
		cin>>a;
		b=a;
		sort(b.begin(),b.end());b+=" ";
		int p=0;
		int f[l];
		memset(f,0,sizeof(f));
		for(int i=0;i<l;i++){
			if(a[i]==b[p]){
				f[i]=1;p++;
			}
		}
		bool ans=1;
		for(int i=0;i<l;i++){
			if(!f[i]&&a[i]==b[p]){
				f[i]=2;p++;
			}
			if(f[i]==0){
				ans=0;break;
			}
		}
		if(ans){
			for(int i=0;i<l;i++)cout<<f[i];
			cout<<'\n';
		}else puts("-");
	}
	return 0;
}