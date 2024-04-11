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

int n,k;
int a[20];
bitset<2001> d[66000];
multiset<pii> s;

void solve(int now,int cs,int r){
	if(!now) return;
	while(cs<=2000){
		for(int i=1;i<=n;i++){
			if(((now>>(i-1))&1)&&cs>=a[i]&&d[now^(1<<(i-1))][cs-a[i]]){
				s.insert(mp(-r,a[i]));
				solve(now^(1<<(i-1)),cs-a[i],r);
				return;
			}
		}
		cs=cs*k,r++;
	}
	assert(0);
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	d[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++) if((i>>(j-1))&1) d[i]|=d[i^(1<<(j-1))]<<a[j];
		for(int j=2000/k;j>=1;j--) if(d[i][j*k]) d[i][j]=1;
	}
	if(!d[(1<<n)-1][1]) return printf("NO\n"),0;
	printf("YES\n");
	solve((1<<n)-1,1,0);
	while(s.size()>1){
		auto it1=s.begin(),it2=it1; it2++;
		assert(it1->fi==it2->fi);
		printf("%d %d\n",it1->se,it2->se);
		int tmp=it1->se+it2->se,dep=-it1->fi;
		while(tmp%k==0) tmp/=k,dep--;
		s.erase(it1); s.erase(it2);
		s.insert(mp(-dep,tmp));
	}
	return 0;
}