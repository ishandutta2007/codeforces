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
int a[1000005],p[1000005];
bool vis[1000005];
mt19937 mrand(time(0)^(unsigned long long)(new char));

void init(int tp,vector<int> &vec){
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=(tp?7*n+1:3*n);i++){
		int x=mrand()%n+1,y=mrand()%n+1;
		while(x==y) y=mrand()%n+1;
		swap(p[x],p[y]);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int num=0;
		for(int j=i;!vis[j];j=p[j]){
			vis[j]=1;
			num++;
		}
		vec.pb(num);
	}
	sort(vec.begin(),vec.end());
}

int main(){
	n=readint();
	if(n==5){
		printf("Petr\n");
		return 0;
	}
	vector<int> v0(0),v1(0),v(0);
	init(0,v0); init(1,v1);
	for(int i=1;i<=n;i++) a[i]=readint();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int num=0;
		for(int j=i;!vis[j];j=a[j]){
			vis[j]=1;
			num++;
		}
		v.pb(num);
	}
	sort(v.begin(),v.end());
	if(abs((int)v.size()-(int)v0.size())<=abs((int)v.size()-(int)v1.size())) printf("Petr\n");
	else printf("Um_nik\n");
	return 0;
}