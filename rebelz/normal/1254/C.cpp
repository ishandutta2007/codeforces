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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[1005],b[1005];
vector<pll> v[2];
vector<int> ans11,ans12,ans21,ans22;

ll ask(int t,int i,int j,int k){
	printf("%d %d %d %d\n",t,i,j,k);
	fflush(stdout);
	return readint();
}

int main(){
	n=readint();
	for(int i=3;i<=n;i++){
		a[i]=ask(1,1,2,i);
		b[i]=ask(2,1,2,i);
		if(b[i]>0) v[1].push_back(mp(a[i],i));
		else v[0].push_back(mp(a[i],i));
	}
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	for(int j=1;j<v[1].size();j++){
		ll tmp=ask(2,1,v[1][j].se,v[1][j-1].se);
		if(tmp>0) ans11.push_back(v[1][j-1].se);
		else ans12.push_back(v[1][j-1].se);
	}
	if(v[1].size()) ans11.push_back(v[1][v[1].size()-1].se);
	for(int j=1;j<v[0].size();j++){
		ll tmp=ask(2,1,v[0][j].se,v[0][j-1].se);
		if(tmp<0) ans21.push_back(v[0][j-1].se);
		else ans22.push_back(v[0][j-1].se);
	}
	if(v[0].size()) ans21.push_back(v[0][v[0].size()-1].se);
	reverse(ans22.begin(),ans22.end());
	reverse(ans11.begin(),ans11.end());
	printf("0 1 ");
	for(auto x:ans21) printf("%d ",x);
	for(auto x:ans22) printf("%d ",x);
	printf("2 ");
	for(auto x:ans12) printf("%d ",x);
	for(auto x:ans11) printf("%d ",x);
	printf("\n");
	fflush(stdout);
	return 0;
}