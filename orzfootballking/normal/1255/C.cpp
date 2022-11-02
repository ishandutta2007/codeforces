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
struct node{
	int a,b,c;
	bool bh(int x,int y){
		RE (a==x||b==x||c==x)&&(a==y||b==y||c==y);
	}
};
V<node> v[100005];node cur;
bool vis[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n-2){
		cin>>cur.a>>cur.b>>cur.c;
		v[cur.a].PB(cur);
		v[cur.b].PB(cur);
		v[cur.c].PB(cur);
	}
	int A,B,C;
	FOR(i,1,n){
		if(v[i].size()==1){
			A=i;break;
		}
	}
	cur=v[A][0];
	if(v[cur.a].size()==2){
		B=cur.a;
	}else if(v[cur.b].size()==2){
		B=cur.b;
	}else B=cur.c;
	vis[A]=1;vis[B]=1;int t;
	FOR(i,1,n-2){
		cout<<A<<' ';
		for(auto u:v[A]){
			t=u.a^u.b^u.c^A^B;
			if(u.bh(A,B)&&!vis[t]){
				vis[t]=1;
				A=B;B=t;
				break;
			}
		}
	}
	cout<<A<<' '<<B;
	RE 0;
}