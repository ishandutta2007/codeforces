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
int fin[2005],a[2005][2005];
vector<int> now[100005];
bool vis[2005];

bool ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	return s[0]=='Y';
}

void reset(){
	printf("R\n");
	fflush(stdout);
}

int main(){
	n=readint(); k=readint();
	if(k==1){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				reset();
				ask(i);
				if(ask(j)) vis[j]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(!vis[i]) ans++;
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	int cnt=0;
	while(1){
		cnt++;
		for(int j=1;j<=n/k*2;j++){
			if(fin[j]==n/k*2-1) continue;
			if(!now[cnt].size()) now[cnt].push_back(j);
			else{
				int tmp=now[cnt][now[cnt].size()-1];
				if(!a[tmp][j]) a[tmp][j]=1,fin[tmp]++,fin[j]++,now[cnt].push_back(j);
			}
		}
		if(!now[cnt].size()){
			cnt--;
			break;
		}
	}
	for(int i=1;i<=cnt;i++){
		reset();
		for(auto x:now[i]) for(int j=(x-1)*(k/2)+1;j<=x*(k/2);j++) if(ask(j)) vis[j]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(!vis[i]) ans++;
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}