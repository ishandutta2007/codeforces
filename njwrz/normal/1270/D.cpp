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
int n,m,a[505];
V<int> q,c;
P<int,int> ask(){
	cout<<"?";
	FOR(i,0,q.size()-1){
		cout<<" "<<q[i];
	}
	cout<<"\n";
	cout.flush();
	P<int,int> t;
	cin>>t.F>>t.S; 
	return t;
}
int main(){
	cin>>n>>m;
	if(m==1){
		cout<<"! 1";return 0;
	}
	FOR(i,1,m)q.PB(i);
	FOR(i,m,n){
		P<int,int> t=ask();
		c.PB(t.F);
		a[t.F]=t.S;
		if(i==n)break;
		FOR(j,0,m-1){
			if(q[j]==t.F){
				q[j]=i+1;
			}
		}
	}
	if(n-m+1>=m){
		q.clear();
		FOR(i,0,m-1){
			q.PB(c[i]);
		}
		P<int,int> t=ask();
		int ans=1;
		FOR(i,0,m-1){
			if(a[t.F]>a[q[i]])ans++;
		}
		cout<<"! "<<ans;return 0;
	}
	int x=c.back();c.pop_back();
	int y=c.back();
	FOR(i,0,q.size()-1)if(q[i]==x)swap(q[i],q[0]);
	int ans=1;
	FOR(i,1,q.size()-1){
		int l=q[i];
		q[i]=y;
		P<int,int> t=ask();
		if(t.F==x)ans+=a[y]<a[x];else ans+=a[y]>a[x];
		q[i]=l;
	}
	cout<<"! "<<ans;
	return 0;
}