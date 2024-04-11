#include<bits/stdc++.h>
#define int long long
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
int num;
void Q(int x){
	cout<<"? "<<x<<'\n';
	fflush(stdout);
	cin>>num;
}
signed main(){
	int n,k;
	cin>>n>>k;
	int B=sqrt(n);
	FOR(i,1,B){
		Q(1);
	}
	FOR(S,1,2)for(int i=S;i<=n;i+=B){
		Q(i);
		if(num>k){
			while(num>k){
				i--;
				if(!i){
					i=n;
				}
				Q(i);
			}
			cout<<"! "<<i<<'\n';RE 0;
		}
	}
	RE 0;
}