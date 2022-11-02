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
V<P<int,int> > v;
void solve(){
	int n;
	cin>>n;int s=sqrt(n);
	v.clear();int t=n;
	FOR(i,2,s){
		if(t%i==0){
			int sum=0;
			while(t%i==0)t/=i,sum++;
			v.PB(MP(i,sum));
		}
	} 
	if(t!=1){
		v.PB(MP(t,1));
	}
	int t1=v[0].F,t2=-1;v[0].S--;n/=t1;
	for(int i=0;i<v.size();i++){
		if(i==0&&v[i].S>=2){
			t2=v[0].F*v[0].F;n/=t2;break;
		}else if(v[i].S&&i){
			t2=v[i].F;n/=t2;break;
		}
	}
	if(t2==-1||n==t1||n==t2||n==1)cout<<"NO\n";
	else{
		cout<<"YES\n";
		cout<<t1<<' '<<t2<<' '<<n<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}