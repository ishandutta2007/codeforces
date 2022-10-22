#pragma GCC optimize("Ofast")
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
char c[200005];
int n,ans[200005];
void solve(){
    scanf("%d%s",&n,c+1);
    FOR(i,1,n)ans[i]=n-i+1;
    int r;
    rep(i,1,n){
    	if(c[i]=='<'){
    		r=i;
    		while(c[r]=='<')r++;
    		reverse(ans+i,ans+r+1);
    		i=r;
		} 
	}
	FOR(i,1,n)printf("%d ",ans[i]);
	putchar('\n');
	FOR(i,1,n)ans[i]=i;
    rep(i,1,n){
    	if(c[i]=='>'){
    		r=i;
    		while(c[r]=='>')r++;
    		reverse(ans+i,ans+r+1);
    		i=r;
		} 
	}
	FOR(i,1,n)printf("%d ",ans[i]);
	putchar('\n');
}
int main(){
	int t;
    scanf("%d",&t);
    while(t--)solve();
	RE 0;
}