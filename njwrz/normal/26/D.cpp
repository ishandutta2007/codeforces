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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int main(){
	double ans=1,a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(b>a+c){
		puts("0");
	}else if(b<=c){
		puts("1");
	}else{
		FOR(i,1,c+1){
			ans=ans*1.0*(b-i+1)/(a+i);
		}
		printf("%.10f",1-ans);
	}
	RE 0;
}