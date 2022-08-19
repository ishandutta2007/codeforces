#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
string s,t,ss,tt;

int main(){
	cin>>s>>t;
	n=readint();
	cout<<s<<' '<<t<<endl;
	for(int i=1;i<=n;i++){
		cin>>ss>>tt;
		if(ss==s) s=tt;
		else if(ss==t) t=tt;
		cout<<s<<' '<<t<<endl;
	}
	return 0;
}