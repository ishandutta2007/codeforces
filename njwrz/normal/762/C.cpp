/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
char c[100005],s[100005];
int l[100005],r[100005],q[100005];
signed main(){
	scanf("%s%s",c+1,s+1);
	int n=strlen(c+1),m=strlen(s+1);
	FOR(i,1,m){
		int t=l[i-1]+1;
		while(t<=n&&c[t]!=s[i])t++;
		l[i]=t;
		if(l[i]<=n)q[l[i]]=i;
	}
	r[m+1]=n+1;
	for(int i=m;i>=1;i--){
		int t=r[i+1]-1;
		while(t>=1&&c[t]!=s[i])t--;
		r[i]=t;
	}
	FOR(i,1,n)gmax(q[i],q[i-1]);
	int minl,minr;
	minl=1,minr=m;
	for(int i=m+1;i>=1;i--){
		if(r[i]>=1){
			int nowl=q[r[i]-1]+1,nowr=i-1;
//			cout<<nowl<<' '<<nowr<<'\n';
			if(nowr-nowl+1<minr-minl+1){
				minl=nowl;
				minr=nowr;
			}
		}
	}
	if(minl==1&&minr==m){
		cout<<'-';RE 0;
	}
	FOR(i,1,m){
		if(i<minl||i>minr){
			cout<<s[i];
		}
	}
	RE 0;
}