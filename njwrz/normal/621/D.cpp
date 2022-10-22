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
long double s[9];
string ans[9]={
"x^y^z",
"x^z^y",
"(x^y)^z",
"y^x^z",
"y^z^x",
"(y^x)^z",
"z^x^y",
"z^y^x",
"(z^x)^y"
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long double x,y,z;
	cin>>x>>y>>z;
	long double tx,ty,tz;
	tx=log(x);ty=log(y);tz=log(z);
	s[0]=pow(y,z)*tx;
	s[1]=pow(z,y)*tx;
	s[2]=y*z*tx;
	s[3]=pow(x,z)*ty;
	s[4]=pow(z,x)*ty;
	s[5]=x*z*ty;
	s[6]=pow(x,y)*tz;
	s[7]=pow(y,x)*tz;
	s[8]=x*y*tz;
	int maxi=0;
	FOR(i,1,8){
		if(s[i]>s[maxi]){
			maxi=i;
		}
	}
	cout<<ans[maxi];
	RE 0;
}