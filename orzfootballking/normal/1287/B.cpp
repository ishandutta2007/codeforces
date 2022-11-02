#pragma GCC optimize(3)
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
string s[1505];int p[3];
string make(string x,string y){
	int len=x.size();
	string re="";
	FOR(i,0,len-1){
		if(x[i]=='S'){
			p[0]++;
		}else if(x[i]=='E'){
			p[1]++;
		}else p[2]++;
		if(y[i]=='S'){
			if(p[0]){
				re+='S';
			}else re+=(p[1]?'T':'E');
		}else if(y[i]=='E'){
			if(p[1]){
				re+='E';
			}else re+=(p[0]?'T':'S');
		}else if(p[2]){
			re+='T';
		}else re+=(p[0]?'E':'S');
		p[0]=p[1]=p[2]=0;
	}
	RE re;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,x;
	cin>>n>>x;
	FOR(i,1,n){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int ans=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<n;j++){
			string t=make(s[i],s[j]);
			if(t==(*lower_bound(s+j+1,s+n+1,t)))ans++;
		}
	}
	cout<<ans;
	return 0;
}