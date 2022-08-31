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

ll n,A,B,tot;
int prm[100005],a[1000005];
ll pre[1000005];
bool fl[100005];
vector<int> dv;

void getprime(int N){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

void getdiv(int tmp){
	dv.clear();
	for(int i=1;i<=tot&&prm[i]<=sqrt(tmp);i++){
		if(tmp%prm[i]==0){
			dv.push_back(prm[i]);
			while(tmp%prm[i]==0) tmp/=prm[i];
		}
	}
	if(tmp>1) dv.push_back(tmp);
}

ll check1(int x){
	vector<ll> v(0);
	for(int i=2;i<=n;i++) if(a[i]%x!=0) v.push_back(i);
	if(!v.size()) return 0;
	ll ret=(v[v.size()-1]-v[0]+1)*A;
	bool fl=0;
	memset(pre,0x3f,sizeof(pre));
	pre[0]=-A*v[0];
	for(int i=1;i<=v.size();i++){
		if((a[v[i-1]]%x==1||a[v[i-1]]%x==x-1)&&!fl){
			if(i==0) pre[i]=-A*v[i];
			else pre[i]=min(pre[i-1],B*i-A*v[i]);
		}
		else{
			fl=1;
			if(i>0) pre[i]=pre[i-1];
		}
	}
	if(!fl) chkmin(ret,(ll)v.size()*B);
	chkmin(ret,pre[v.size()-1]+(v[v.size()-1]+1)*A);
	fl=0;
	for(int i=v.size()-1;i>=1;i--){
		if((a[v[i]]%x==1||a[v[i]]%x==x-1)&&!fl) chkmin(ret,B*(ll)(v.size()-i)+(v[i-1]+1)*A+pre[i-1]);
		else fl=1;
	}
	return ret;
}

ll check2(int x){
	vector<ll> v(0);
	for(int i=1;i<=n-1;i++) if(a[i]%x!=0) v.push_back(i);
	if(!v.size()) return 0;
	ll ret=(v[v.size()-1]-v[0]+1)*A;
	bool fl=0;
	memset(pre,0x3f,sizeof(pre));
	pre[0]=-A*v[0];
	for(int i=1;i<=v.size();i++){
		if((a[v[i-1]]%x==1||a[v[i-1]]%x==x-1)&&!fl){
			if(i==0) pre[i]=-A*v[i];
			else pre[i]=min(pre[i-1],B*i-A*v[i]);
		}
		else{
			fl=1;
			if(i>0) pre[i]=pre[i-1];
		}
	}
	if(!fl) chkmin(ret,(ll)v.size()*B);
	chkmin(ret,pre[v.size()-1]+(v[v.size()-1]+1)*A);
	fl=0;
	for(int i=v.size()-1;i>=1;i--){
		if((a[v[i]]%x==1||a[v[i]]%x==x-1)&&!fl) chkmin(ret,B*(ll)(v.size()-i)+(v[i-1]+1)*A+pre[i-1]);
		else fl=1;
	}
	return ret;
}

int main(){
	getprime(100000);
	n=readint(); A=readint(); B=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	if(n==1) return printf("0\n"),0;
	ll ans=1ll<<60;
	getdiv(a[1]);
	for(auto x:dv) chkmin(ans,check1(x));
	getdiv(a[1]+1);
	for(auto x:dv) chkmin(ans,check1(x)+B);
	getdiv(a[1]-1);
	for(auto x:dv) chkmin(ans,check1(x)+B);
	getdiv(a[n]);
	for(auto x:dv) chkmin(ans,check2(x));
	getdiv(a[n]+1);
	for(auto x:dv) chkmin(ans,check2(x)+B);
	getdiv(a[n]-1);
	for(auto x:dv) chkmin(ans,check2(x)+B);
	printf("%lld\n",ans);
	return 0;
}