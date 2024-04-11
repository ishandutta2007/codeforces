#include <bits/stdc++.h>
using namespace std;
int zh[30],maxi;
char ans;
int vis[5001],v[5001],f[5005];
bool ss(int a){
	if(a<2)return 0;
	for(int i=2;i*i<=a;i++)
		if(a%i==0)return 0;
	return 1;
}
int main(){
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		zh[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(zh[i]>maxi){
			maxi=zh[i];
			ans=(char)('a'+i);
		}
	}
	int m=0;
	for(int i=2;i<=n;i++){
		if(ss(i)){
			vis[++m]=i;
		}
	}
	v[1]=2;
	int len=1;
	for(int i=2;i<=m;i++){
		if(vis[i]*2<=n)v[++len]=vis[i];
	}
	int ans1=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=len;j++){
			if(i%v[j]==0){
				f[i]=1;ans1++;break;
			}
		}
	}
	if(ans1>maxi){
		cout<<"NO";return 0;
	}
	cout<<"YES\n";
	int t=0;
	zh[(int)(ans-'a')]-=ans1;
	char shu[5005];
	for(int i=1;i<=n;i++){
		if(f[i]){
			shu[i]=ans;
		}else{
			while(!zh[t]){
				t++;
			}
			zh[t]--;
			shu[i]=(char)(t+'a');
		}
	}
	for(int i=1;i<=n;i++)cout<<shu[i];
	return 0;
}