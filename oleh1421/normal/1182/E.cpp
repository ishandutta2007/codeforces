
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<vector<ll> > mn(vector<vector<ll> >a,vector<vector<ll> >b){
    vector<vector<ll> >c(3ll,{0ll,0ll,0ll});
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            for (int t=0;t<3;t++){
                c[i][j]+=1ll*a[i][t]*b[t][j];
                c[i][j]%=1000000006ll;
            }
        }
    }
    return c;
}
vector<vector<ll> >bpow(vector<vector<ll> >v,ll m){
         if (m==1ll) return v;
         if (m%2) return mn(v,bpow(v,m-1ll));
         else {
            vector<vector<ll> >x=bpow(v,m/2ll);
            return mn(x,x);
         }
}
ll bpow1(ll a,ll m,ll mod){
   if (m==0) return 1ll;
   if (m%2) return (a*bpow1(a,m-1ll,mod))%mod;
   else{
     ll x=bpow1(a,m/2ll,mod);
     return (x*x)%mod;
   }
}
int main()
{
    ll n,f1,f2,f3,c;cin>>n>>f1>>f2>>f3>>c;
    vector<vector<ll> >a(3ll,{0ll,0ll,0ll});
    a[0][0]=1ll;
    a[1][0]=1ll;
    a[2][0]=1ll;
    a[0][1]=1ll;
    a[1][2]=1ll;
    vector<vector<ll> >v=bpow(a,n-3ll);
    ll c1=v[0][1];
    ll c2=v[1][0];
    ll c3=v[0][0];
    ll res=1ll;
    res*=bpow1(f1,c1,1000000007ll);
    res%=1000000007ll;
    res*=bpow1(f2,c2,1000000007ll);
    res%=1000000007ll;
    res*=bpow1(f3,c3,1000000007ll);
    res%=1000000007ll;
    ll p=(c1+c2+c2+c3+c3+c3-(n%1000000006ll)*1ll+1000000006ll)%1000000006ll;
    res*=bpow1(c,p,1000000007ll);
    res%=1000000007ll;
    cout<<res;
    return 0;
}

/*
//
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int MO = 1e9+7;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		y>>=1;
		x=mul(x,x);
	}
	return z;
}
int n=5;
struct node{
	int a[5][5];
	node(){
		memset(a,0,sizeof(a));
	}
}o,f,g;
int mo=MO-1;
int ad2(int&x,int y){
	x+=y;
	if(x>=mo)
		x-=mo;
}
int mul2(int x,int y){
	return (LL)x*y%mo;
}
node mul(node p,node q){
	node r;
	int i,j,k;
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1)
			for(k=0;k<n;k=k+1)
				ad2(r.a[i][k],mul2(p.a[i][j],q.a[j][k]));
	return r;
}
int main()
{
	LL m;
	int c,x,y,z,i,s;
	cin>>m>>x>>y>>z>>c;
	o.a[0][0]=1;
	o.a[0][1]=1,o.a[1][1]=1;
	o.a[3][2]=1;
	o.a[4][3]=1;
	o.a[1][4]=2,o.a[2][4]=1,o.a[3][4]=1,o.a[4][4]=1;
	f=o;
	for(i=0;i<n;i=i+1)
		g.a[i][i]=1;
	m--;
	while(m){
		if(m&1)
			g=mul(g,f);
		f=mul(f,f);
		m>>=1;
	}
	cout<<g.a[2][2]<<" "<<g.a[3][2]<<" "<<g.a[4][2]<<" "<<g.a[0][2]+g.a[1][2]<<endl;
	s=fpow(c,g.a[0][2]);
	s=mul(s,fpow(c,g.a[1][2]));
	s=mul(s,fpow(x,g.a[2][2]));
	s=mul(s,fpow(y,g.a[3][2]));
	s=mul(s,fpow(z,g.a[4][2]));
	cout<<s;
	return 0;
}*/
/*
1000000000000000000 1000000000 1000000000 1000000000 1000000000
465472707 651349001 173762317 1289457618
607659049
*/
//1-0
//3-1
//5-2
//7 3
//9 4