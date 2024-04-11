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
ll a[12],n,i,j,x,y,z,minn=0,t;
vector <ll> all;
/*********FUNCTIONS**************/
 
 
/***********MAIN**************/
 
signed main(){ cin>>n;
	for (i=1;i<=n;i++) {minn=0; cin>>x>>y>>z;
	if ((z>=x)or(z>=y)) {if (x<y) cout<<x<<endl; else cout<<y<<endl;  continue;}
	x-=z;y-=z; minn+=z;
	z=(x>y)?x:y;
	y=(x<y)?x:y;
	x=z;
	//cout<<x<<' '<<y<<endl;
	if (x>(2*y)) {minn+=y; cout<<minn<<endl; continue;}
	{minn+=x-y; y-=(x-y); minn+=(y/3)*2; if (y%3==2) minn++; cout<<minn<<endl; continue;}
	}
}