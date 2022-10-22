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
int p[1048576],len=1048576;
void add(int x,int y){
	while(x<len){
		p[x]+=y;
		x+=x&-x;
	}
}
int search(int x){
	int now=0;
	for(int i=len/2;i>=1;i>>=1){
		if(p[now+i]<x){
			x-=p[now+i];
			now+=i;
		}
	}
	RE now+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q,cnt;
	cin>>n>>q;
	cnt=n;
	int x;
	FOR(i,1,n){
		cin>>x;
		add(x,1);
	}
	cnt=n;
	FOR(i,1,q){
		cin>>x;
		if(x<0){
			int t=search(-x);
			add(t,-1);cnt--;
		}else{
			add(x,1);
			cnt++;
		}
	} 
	if(!cnt){
		cout<<0;
	}else{
		cout<<search(1);
	} 
	RE 0;
}