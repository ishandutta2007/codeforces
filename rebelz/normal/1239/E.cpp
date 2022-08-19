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
typedef pair<ll,int> pli;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[55],ans[5][55],k[50],c1[(1<<24)+1],c2[(1<<24)+1];
unordered_map<int,int> lg2;
int cnt[(1<<24)+1];
vector<int> s[25];

int main(){
	n=readint();
	for(int i=1;i<=n+n;i++) a[i]=readint();
	sort(a+1,a+n+n+1);
	ans[1][1]=a[1],ans[2][n]=a[2];
	for(int i=1;i<=n+n-2;i++) a[i]=a[i+2];
	n--;
	for(int i=1;i<=n;i++) lg2[1<<(i-1)]=i;
	c1[0]=0,c2[0]=0;
	for(int i=1;i<=n;i++) c2[0]+=a[i];
	s[0].push_back(c1[0]-c2[0]);
	for(int i=1;i<(1<<n);i++){
		int tmp=i&(-i);
		c1[i]=c1[i-tmp]+a[lg2[tmp]];
		c2[i]=c2[i-tmp]-a[lg2[tmp]];
		cnt[i]=cnt[i-tmp]+1;
		s[cnt[i]].push_back(c1[i]-c2[i]);
	}
	for(int i=0;i<=n;i++) sort(s[i].begin(),s[i].end());
	int res=1<<30; pair<pii,int> opt;
	c1[0]=0,c2[0]=0;
	for(int i=1;i<=n;i++) c2[0]+=a[n+n-i+1];
	for(int i=1;i<(1<<n);i++){
		int tmp=i&(-i);
		c1[i]=c1[i-tmp]+a[n+n-lg2[tmp]+1];
		c2[i]=c2[i-tmp]-a[n+n-lg2[tmp]+1];
		auto it=lower_bound(s[n-cnt[i]].begin(),s[n-cnt[i]].end(),c2[i]-c1[i]);
		if(it==s[n-cnt[i]].end()) continue;
		if(chkmin(res,c1[i]-c2[i]+*it)) opt=mp(mp(*it,i),n-cnt[i]);
	}
//	cout<<opt.fi<<' '<<opt.se<<endl;
	c1[0]=0,c2[0]=0;
	for(int i=1;i<=n;i++) c2[0]+=a[i];
	bool fl=false;
	for(int i=1;i<(1<<n);i++){
		int tmp=i&(-i);
		c1[i]=c1[i-tmp]+a[lg2[tmp]];
		c2[i]=c2[i-tmp]-a[lg2[tmp]];
		if(c1[i]-c2[i]==opt.fi.fi&&cnt[i]==opt.se){
			opt.fi.fi=i;
			fl=true;
			break;
		}
	}
	if(!fl&&c1[0]-c2[0]==opt.fi.fi) opt.fi.fi=0;
	for(int i=1;i<=n;i++) k[i]=(opt.fi.fi>>(i-1))&1;
	int now1=1,now2=1;
	for(int i=1;i<=n;i++){
		if(k[i]) ans[2][n-now1+1]=a[i],now1++;
		else ans[1][now2+1]=a[i],now2++;
	}
	for(int i=1;i<=n;i++) k[i]=(opt.fi.se>>(i-1))&1;
	for(int i=1;i<=n;i++){
		if(k[i]) ans[2][n-now1+1]=a[n+n-i+1],now1++;
		else ans[1][now2+1]=a[n+n-i+1],now2++;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n+1;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}