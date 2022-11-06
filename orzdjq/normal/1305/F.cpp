#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=200005;
LL a[Maxn];
int n;
bool isp[1000005];
vector<int> P,p;
void _init(){
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=false;
	for (int i=2;i<1000005;i++){
		if (isp[i]){
			for (int j=i+i;j<1000005;j+=i) isp[j]=false;
			if (i<=1000){
				P.pb(i);
			}
			p.pb(i);
		}
	}
}
time_t st,ed;
int res;
void Test(LL x){
	LL rr=0;
	for (int i=1;i<=n;i++){
		LL v=a[i]%x;
		if (a[i]<x)rr+=x-v;
		else rr+=min(v,x-v);
	}
	//if (rr==)
	if (rr<1e9) res=min(res,(int)rr);
}
void test(LL v){
	if (v<0) v=-v;
	if (v==0) return; 
	for (int i=0;i<p.size();i++){
		if (1ll*p[i]*p[i]>v) break;
		if (v%p[i]==0){
			if (p[i]>1000) Test(p[i]);
			while (v%p[i]==0) v/=p[i]; 
		}
	}
	if (v!=1) Test(v);
}
int main(){
	srand(time(0));
	st=clock();
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	_init();
	res=1e9;
	for (int i=0;i<P.size();i++){
		int x=P[i];
		int cnt=0;
		for (int j=1;j<=n;j++){
			int v=a[j]%x;
			if (a[j]<x)cnt+=x-v;
			else cnt+=min(v,x-v);
		}
		//if (cnt==3) cout<<x<<endl;
		res=min(res,cnt);
	}
	//cout<<res<<endl;
	while (1){
		ed=clock();
		if ((double)(ed-st)/CLOCKS_PER_SEC>=2.0) break;
		int x=(rand()*rand())%n+1;
		for (int i=-2;i<=2;i++) if (a[x]+i>=0) test(a[x]+i);
	}
	printf("%d\n",res);
}