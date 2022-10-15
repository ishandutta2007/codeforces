// Credit to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long 
#define ll int64_t 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
 
/*********VARIABLE****************/

typedef pair<int,int> ii;
/******************************/
const ll po[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
ll a[12],n,i,j,x,y,minn=0,t;
vector <ll> all;
/*********FUNCTIONS**************/
 
 
/***********MAIN**************/
 
signed main(){
	cin>>t; y=0;
	while (t>0) { y=0;
	for (i=0;i<=11;i++) a[i]=0;
	cin>>n;
	for (i=1;i<=n;i++) {cin>>x; if (x==2048) { if (!y)cout<<"Yes"<<endl; y=1; }
	
	for (j=0;j<=10;j++) if (x==po[j]) a[j]++;
	}if (y) {t--;continue;}	
	for (i=0;i<=10;i++) a[i+1]+=a[i]/2;
	if (a[11]>=1) cout<<"Yes"; else cout<<"No";
	cout<<endl; t--;
	}
}
 
//