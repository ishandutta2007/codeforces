#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n;char c[505];
int main(){
	scanf("%d%s",&n,c+1);
	int s=0;
	FOR(i,1,n)if(c[i]==')')s--;else s++;
	if(s){
		cout<<"0 1 1";RE 0;
	}
	int ans=-10,ans1,ans2;
	FOR(i,1,n){
		FOR(j,i,n){
			swap(c[i],c[j]);
			int mini=0,sum=0;
			FOR(k,1,n){
				if(c[k]==')')s--;else s++;
				mini=min(mini,s);
			}
			FOR(k,1,n){
				if(c[k]==')')s--;else s++;
				if(s==mini)sum++;
			}
			if(sum>ans){
				ans=sum;
				ans1=i;ans2=j;
			}
			swap(c[i],c[j]);
		}
	}
	cout<<ans<<'\n'<<ans1<<' '<<ans2;
	RE 0;
}