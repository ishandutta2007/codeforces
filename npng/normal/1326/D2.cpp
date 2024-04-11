#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;

char s[N];
char str[N*2];
int len[N*2];

pair<int,int> Manacher(int l,int r) {
	str[0]='$';
	int k=0;
	for(int i=l; i<=r; i++) str[++k]='#',str[++k]=s[i];
	str[++k]='#';
	len[0]=0;
	int id=0,mx=0;
	int mxl=0,mxr=0;
	for(int i=1; i<=k; i++) {
		len[i]=i<mx?min(mx-i,len[2*id-i]):1;
		while(i-len[i]>=0&&i+len[i]<=k&&str[i-len[i]]==str[i+len[i]]) ++len[i];
		if(len[i]+i>mx)mx=len[i]+i,id=i;
		if(len[i]==i) {
			if(len[i]-1>mxl) mxl=len[i]-1;
		} else if(len[i]==k-i+1) {
			if(len[i]-1>mxr) mxr=len[i]-1;
		}
	}
	if(mxl>mxr) return make_pair(0,mxl);
	else return make_pair(1,mxr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		int l=0,r=strlen(s)-1;
		while(l<r&&s[l]==s[r]) l++,r--;
		if(l>=r){
			cout<<s<<endl;
			continue;
		}
		pair<int,int> res=Manacher(l,r);
		for(int i=0;i<l;i++){
			cout<<s[i];
		}
		if(res.first==0){
			for(int i=l;i<=l+res.second-1;i++){
				cout<<s[i];
			}
		}
		else if(res.first==1){
			for(int i=r-res.second+1;i<=r;i++){
				cout<<s[i];
			}
		}
		for(int i=l-1;i>=0;i--){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}