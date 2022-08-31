#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
char s[2005],t[2005];
int q[2005];
pii fr[2005];
bool vis[2005];

void work(char *s,vector<pii> &op){
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=s[i]=='1';
	for(int i=1;i<=cnt-k-1;i++){
		int tmp=i+k-1,pl=0;
		for(int j=1;j<=n;j++){
			if(s[j]=='1'){
				tmp--;
				if(!tmp){
					pl=j;
					break;
				}
			}
		}
		op.pb(mp(i,pl));
		reverse(s+i,s+pl+1);
	}
	int tmp=cnt-k,lf=0,rg=0,now=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			tmp--;
			if(!tmp){
				lf=i;
				break;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='1'){
			rg=i;
			break;
		}
	}
	for(int i=2;i<=k+1;i++){
		if(!now){
			op.pb(mp(lf,rg-1));
			reverse(s+lf,s+rg);
			for(int j=lf;j<=rg;j++){
				if(s[j]=='1'){
					lf=j;
					break;
				}
			}
			now=1;
		}
		else{
			op.pb(mp(lf+1,rg));
			reverse(s+lf+1,s+rg+1);
			for(int j=rg;j>=lf;j--){
				if(s[j]=='1'){
					rg=j;
					break;
				}
			}
			now=0;
		}
	}
	if(!(k&1)){
		op.pb(mp(cnt-k,rg-1));
		reverse(s+cnt-k,s+rg);
		return;
	}
	else{
		int front=0,rear=0;
		memset(vis,0,sizeof(vis));
		memset(fr,0,sizeof(fr));
		q[rear++]=cnt-k-1,vis[cnt-k-1]=1;
		bool fl=0;
		while(front<rear){
			int t=q[front++];
			if(t==cnt){
				fl=1;
				break;
			}
			for(int i=0;i<=k;i++){
				if(i<=t&&k-i<=cnt-t){
					if(!vis[t+k-i-i]){
						vis[t+k-i-i]=1;
						fr[t+k-i-i]=mp(t,i);
						q[rear++]=t+k-i-i;
					}
				}
			}
		}
		int tmp=cnt;
		vector<int> vec(0);
		while(tmp!=cnt-k-1){
			vec.pb(fr[tmp].se);
			tmp=fr[tmp].fi;
		}
		reverse(vec.begin(),vec.end());
		int A=cnt-k-1,B=k+1;
		for(auto r:vec){
			op.pb(mp(A-r+1,rg-B+(k-r)));
			reverse(s+A-r+1,s+rg-B+(k-r)+1);
			A=A+k-r-r,B=B-k+r+r;
		}
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		scanf("%s%s",s+1,t+1);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++) cnt1+=s[i]=='1';
		for(int i=1;i<=n;i++) cnt2+=t[i]=='1';
		if(cnt1!=cnt2){
			printf("-1\n");
			continue;
		}
		if(!cnt1){
			printf("0\n");
			continue;
		}
		if(!k||k>cnt1){
			if(strcmp(s+1,t+1)) printf("-1\n");
			else printf("0\n");
			continue;
		}
		vector<pii> ans1(0),ans2(0);
		if(k==cnt1){
			int pl1=0,pl2=0;
			for(int i=n;i>=1;i--){
				if(s[i]=='1'){
					pl1=i;
					break;
				}
			}
			ans1.pb(mp(1,pl1));
			reverse(s+1,s+pl1+1);
			for(int i=n;i>=1;i--){
				if(t[i]=='1'){
					pl2=i;
					break;
				}
			}
			ans2.pb(mp(1,pl2));
			reverse(t+1,t+pl2+1);
			for(int i=n;i>=1;i--){
				if(s[i]=='1'){
					pl1=i;
					break;
				}
			}
			for(int i=n;i>=1;i--){
				if(t[i]=='1'){
					pl2=i;
					break;
				}
			}
			for(int i=1;i<=pl1;i++){
				if(s[i]==s[pl1-i+1]) continue;
				if(s[i]<s[pl1-i+1]){
					ans1.pb(mp(1,pl1));
					reverse(s+1,s+pl1+1);
				}
				break;
			}
			for(int i=1;i<=pl2;i++){
				if(t[i]==t[pl2-i+1]) continue;
				if(t[i]<t[pl2-i+1]){
					ans2.pb(mp(1,pl2));
					reverse(t+1,t+pl2+1);
				}
				break;
			}
			if(strcmp(s+1,t+1)) printf("-1\n");
			else{
				printf("%d\n",ans1.size()+ans2.size());
				for(int i=0;i<ans1.size();i++) printf("%d %d\n",ans1[i].fi,ans1[i].se);
				for(int i=ans2.size()-1;i>=0;i--) printf("%d %d\n",ans2[i].fi,ans2[i].se);
			}
			continue;
		}
		work(s,ans1);
		work(t,ans2);
		if(strcmp(s+1,t+1)) printf("-1\n");
		else{
			printf("%d\n",ans1.size()+ans2.size());
			for(int i=0;i<ans1.size();i++) printf("%d %d\n",ans1[i].fi,ans1[i].se);
			for(int i=ans2.size()-1;i>=0;i--) printf("%d %d\n",ans2[i].fi,ans2[i].se);
		}
	}
	return 0;
}