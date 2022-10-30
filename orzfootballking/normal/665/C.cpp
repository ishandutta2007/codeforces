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
char c[200005];
signed main(){
	scanf("%s",c+1);
	int len;
	c[0]='A';
	len=strlen(c+1);
	int lst=0;
	c[len+1]='A';
	FOR(i,2,len+1){
		if(c[i]!=c[i-1]){
			int len=i-1-lst;
			if(len&1){
				for(int j=lst+2;j<i-1;j+=2){
					rep(k,0,26){
						if(k+'a'!=c[i-1]){
							c[j]=k+'a';
						}
					}
				}
			}else{
				for(int j=lst+1;j<i-1;j+=2){
					rep(k,0,26){
						if(k+'a'!=c[j-1]&&k+'a'!=c[j+1]){
							c[j]=k+'a';
						}
					}
				}
			}
			lst=i-1;
		}
	}
	FOR(i,1,len){
		cout<<c[i];
	}
	RE 0;
}