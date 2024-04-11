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
int f[100005][2],ct[2];
char s[100005];
vector<int> ans[100005];

int getf(int x,int t){return x==f[x][t]?x:f[x][t]=getf(f[x][t],t);}

void getans(){
	for(int i=1;i<=n+1;i++) f[i][0]=f[i][1]=i;
	for(int i=1;i<=n;i++){
		if(s[i]=='L') f[getf(i,0)][0]=getf(i+1,0);
		else f[getf(i,1)][1]=getf(i+1,1);
	}
	int now=-1,cnt=0,pl=0;
	while(getf(1,0)!=getf(n,0)||getf(1,1)!=getf(n,1)){
		cnt++,now=-1;
		for(int i=min(getf(1,0),getf(1,1));i<=n;i=getf(i+1,now)){
			if(now<0||(s[i]=='L')==now){
				ans[cnt].push_back(i);
				if(now<0) now=s[i]=='L';
				f[getf(i,now)][now]=getf(i+1,now);
				if(now>=0) now^=1;
				else now=(s[i]=='L')^1;
			}
		}
	}
	printf("%d\n",cnt-1);
	sort(ans+1,ans+cnt+1,[&](vector<int> x,vector<int> y){
		if((s[x[0]]=='L')==(s[y[0]]=='L')){
			if(s[x[0]]=='R') return (s[x[x.size()-1]]=='L')>(s[y[y.size()-1]]=='L');
			else return (s[x[x.size()-1]]=='L')<(s[y[y.size()-1]]=='L');
		}
		return (s[x[0]]=='L')<(s[y[0]]=='L');
	});
	int s0=1,s1=1,t1=0,sum=0;
	while(s1<=cnt&&s[ans[s1][0]]=='R') s1++;
	t1=s1;
	if(ct[0]>ct[1]) now=0;
	else now=1;
	if(ct[0]==ct[1]){
		bool fl=1;
		now=0;
		while(sum<n){
			if(now==0){
				if(s0==t1){
					fl=0;
					break;
				}
				for(auto x:ans[s0]) sum++;
				if(s[ans[s0][ans[s0].size()-1]]=='R') now=1;
				s0++;
			}
			else{
				if(s1==cnt+1){
					fl=0;
					break;
				}
				for(auto x:ans[s1]) sum++;
				if(s[ans[s1][ans[s1].size()-1]]=='L') now=0;
				s1++;
			}
		}
		if(!fl){
			now=1,sum=0,s0=1,s1=t1;
			while(sum<n){
				if(now==0){
					for(auto x:ans[s0]) printf("%d ",x),sum++;
					if(s[ans[s0][ans[s0].size()-1]]=='R') now=1;
					s0++;
				}
				else{
					for(auto x:ans[s1]) printf("%d ",x),sum++;
					if(s[ans[s1][ans[s1].size()-1]]=='L') now=0;
					s1++;
				}
			}
		}
		else{
			now=0,sum=0,s0=1,s1=t1;
			while(sum<n){
				if(now==0){
					for(auto x:ans[s0]) printf("%d ",x),sum++;
					if(s[ans[s0][ans[s0].size()-1]]=='R') now=1;
					s0++;
				}
				else{
					for(auto x:ans[s1]) printf("%d ",x),sum++;
					if(s[ans[s1][ans[s1].size()-1]]=='L') now=0;
					s1++;
				}
			}
		}
	}
	else{
		while(sum<n){
			if(now==0){
				for(auto x:ans[s0]) printf("%d ",x),sum++;
				if(s[ans[s0][ans[s0].size()-1]]=='R') now=1;
				s0++;
			}
			else{
				for(auto x:ans[s1]) printf("%d ",x),sum++;
				if(s[ans[s1][ans[s1].size()-1]]=='L') now=0;
				s1++;
			}
		}
	}
	printf("\n");
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	if(n==1) return printf("0\n1\n"),0;
	for(int i=1;i<=n;i++) ct[s[i]=='L']++;
	getans();
	return 0;
}