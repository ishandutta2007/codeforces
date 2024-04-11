#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define ll long long
#define ld double
using namespace std;
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n; char str[300];

int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	int cnt0=0,cnt1=0;
	F(i,1,n){
		if(str[i]=='0') ++cnt0;
		else ++cnt1;
	}
	if(cnt0==1&&cnt1==0) printf("0");
	else{
		printf("1");
		F(i,1,cnt0) printf("0");
	}
	return 0;
}