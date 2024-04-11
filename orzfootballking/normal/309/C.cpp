#pragma GCC optimize(3)
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
int a[40],b[1000005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,m,x;
	cin>>n>>m;
	FOR(i,1,n){
		cin>>x;
		int t=1;
		FOR(j,0,29){
			if(x&t)a[j]++;
			t*=2;
		}
	}
	FOR(i,1,m){
		cin>>b[i];
	}
	sort(b+1,b+m+1);
	FOR(i,1,m){
		bool f=0;
		FOR(j,b[i],29){
			if(a[j]){
				a[j]--;
				for(int k=b[i];k<j;k++)a[k]++;
				f=1;break;
			}
		}
		if(!f){
			cout<<i-1;RE 0;
		}
	}
	cout<<m;
	RE 0;
}