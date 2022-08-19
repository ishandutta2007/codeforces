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

const int cys=1000000007,base=31;
int n,m,q,l;
char s0[105],t[100005],s[1000005];
ll pre[100005][30],pw2[100005],ipw2[100005];
ull hs[105],h[1000005],pw[100005];
map<int,ll> bk[25];

ll mod(ll x){return x>=cys?x-cys:x;}

ll getans(char ch,int dep,int mx){
	if(dep==mx) return 0;
	return mod(pre[mx-1][ch-'a']+cys-(dep?pre[dep-1][ch-'a']:0))*ipw2[n-mx]%cys;
}

ll work(int num,int dep,int mx){
	if(bk[dep].count(num)) return bk[dep][num];
	if(dep==mx){
		if(num) return 0;
		return 1;
	}
	if(num==1) return mod(pre[mx-1][t[dep]-'a']+cys-(dep?pre[dep-1][t[dep]-'a']:0))*ipw2[n-mx]%cys;
	if(t[dep]!=t[dep+1]){
		if(num>3) return bk[dep][num]=0;
		else if(num==2) return bk[dep][num]=mod(2*getans(t[dep],dep+1,mx));
		else if(num==3) return bk[dep][num]=getans(t[dep],dep+1,mx);
	}
	return bk[dep][num]=work(num/2,dep+1,mx)+work((num+1)/2,dep+1,mx);
}

ll solve(vector<char> &v,int dep,int mx){
	if(!v.size()) return pw2[mx-dep];
	if(dep==mx){
		if(v.size()) return 0;
		return 1;
	}
	if(v.size()==1) return mod(pre[mx-1][v[0]-'a']+cys-(dep?pre[dep-1][v[0]-'a']:0))*ipw2[n-mx]%cys;
	bool fl[2]={1,1};
	for(int i=0;i<v.size();i++) if(v[i]!=t[dep]) fl[i&1]=0;
	if(fl[0]&&fl[1]){
		for(int i=0;i<=21;i++) bk[i].clear();
		return work(v.size(),dep,mx);
	}
	else if(fl[0]){
		vector<char> v1(0);
		for(int i=1;i<v.size();i+=2) v1.pb(v[i]);
		return solve(v1,dep+1,mx);
	}
	else if(fl[1]){
		vector<char> v1(0);
		for(int i=0;i<v.size();i+=2) v1.pb(v[i]);
		return solve(v1,dep+1,mx);
	}
	return 0;
}

int main(){
	n=readint(); q=readint();
	scanf("%s%s",s0+1,t);
	m=strlen(s0+1);
	for(int i=1;i<=m;i++) hs[i]=hs[i-1]*base+s0[i]-'a';
	pw[0]=pw2[0]=ipw2[0]=1;
	for(int i=1;i<=m;i++) pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%cys;
	for(int i=1;i<=n;i++) ipw2[i]=ipw2[i-1]*((cys+1)/2)%cys;
	pre[0][t[0]-'a']=pw2[n-1];
	for(int i=1;i<n;i++){
		for(int j=0;j<26;j++) pre[i][j]=pre[i-1][j];
		pre[i][t[i]-'a']=(pre[i][t[i]-'a']+pw2[n-i-1])%cys;
	}
	int k;
	while(q--){
		k=readint();
		scanf("%s",s+1);
		l=strlen(s+1);
		for(int i=1;i<=l;i++) h[i]=h[i-1]*base+s[i]-'a';
		ll ans=0;
		for(int i=1;i<=m+1;i++){
			if(i>1){
				int ed=min(i-2,l);
				if(h[ed]!=hs[m-i+2+ed]-hs[m-i+2]*pw[ed]) continue;
			}
			bool fl=1;
			for(int j=i;j<=l;j+=m+1){
				if(j+m-1>l){
					if(hs[l-j+1]!=h[l]-h[j-1]*pw[l-j+1]){
						fl=0;
						break;
					}
				}
				else if(hs[m]!=h[j+m-1]-h[j-1]*pw[m]){
					fl=0;
					break;
				}
			}
			if(!fl) continue;
			vector<char> v;
			if(i>1&&i-1<=l) v.pb(s[i-1]);
			for(int j=i;j+m<=l;j+=m+1) v.pb(s[j+m]);
//			for(auto r:v) cout<<r<<' ';
//			cout<<endl;
			ans=(ans+solve(v,0,k))%cys;
		}
		printf("%lld\n",ans);
	}
	return 0;
}