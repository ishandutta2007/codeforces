#pragma GCC optimize("Ofast,unroll-loops")
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
int t[105],n,m,a[200005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	int s=0,ans=0,sum=0;
	FOR(i,1,n){
		cin>>a[i];
		sum+=a[i];
		ans=0;
		if(sum>m){
			s=sum-m;
			for(int j=100;j>=1;j--){
				if(s<=t[j]*j){
					int p=s/j+(s%j!=0);
					s-=p*j;ans+=p;break;
				}else s-=t[j]*j,ans+=t[j];
			}
		}
		cout<<ans<<'\n';
		t[a[i]]++;
	}
	RE 0;
}