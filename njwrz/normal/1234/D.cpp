#include <bits/stdc++.h>
using namespace std;
int a[400005][27],tt[27];
int n,l[400005],r[400005];
void change(int p,int id,char mb,char yb){
	if(l[p]>id||r[p]<id)return;
	a[p][yb-'a']--;
	a[p][mb-'a']++;
	if(p>=n)return;
	change(p*2,id,mb,yb);
	change(p*2+1,id,mb,yb);
}
void pl(int p,int ll,int rr){
	if(l[p]>rr||r[p]<ll)return;
	if(rr>=r[p]&&ll<=l[p]){
		for(int i=0;i<26;i++){
			if(a[p][i]){
				tt[i]=1;
			}
		}
		return;
	}
	if(p>=n)return;
	pl(2*p,ll,rr);
	pl(2*p+1,ll,rr);
}
int main(){
	string s;
	cin>>s;n=s.size();
	int t=1;
	while(t<n)t*=2;
	for(int i=t;i<n+t;i++){
		a[i][s[i-t]-'a']=1;l[i]=i-t;r[i]=i-t;
	}
	for(int i=n+t;i<t*2;i++){
		l[i]=i-t;r[i]=i-t;
	}
	n=t;
	for(int i=n-1;i>0;i--){
		for(int j=0;j<26;j++)a[i][j]=a[i*2][j]+a[i*2+1][j];
		l[i]=l[2*i];
		r[i]=r[2*i+1];
	}
	int x,y;char c;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>x;
		if(x==1){
			cin>>x>>c;x--;
			change(1,x,c,s[x]);
			s[x]=c;
		}else{
			cin>>x>>y;x--;y--;
			memset(tt,0,sizeof(tt));
			pl(1,x,y);
			int ans=0;
			for(int j=0;j<26;j++)ans+=tt[j];
			cout<<ans<<'\n';
		}
	}
	return 0;
}