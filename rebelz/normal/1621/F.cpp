// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,a,b,c,cnt;
int seq[100005];
char s[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); a=readint(); b=readint(); c=readint();
		scanf("%s",s+1);
		vector<pii> vec(0);
		int now=1;
		for(int i=1;i<=n;i++){
			if(s[i]!=s[i+1]){
				vec.pb(mp(s[i]-'0',now));
				now=1;
			}
			else now++;
		}
		cnt=0;
		for(int i=1;i<vec.size()-1;i++)
			if(vec[i].fi==0)
				seq[++cnt]=vec[i].se;
		sort(seq+1,seq+cnt+1);
		int num0=0;
		for(auto r:vec) if(!r.fi) num0+=r.se-1;
		int num1=0;
		for(auto r:vec) if(r.fi) num1+=r.se-1;
//		cout<<"test "<<num0<<' '<<num1<<endl;
		for(int i=1;i<=cnt;i++) seq[i]+=seq[i-1];
		ll ans=0;
		for(int i=0;i<=cnt;i++){
			int now0=num0+i,now1=num1+i;
			if(seq[i]>=now1+1){
				continue;
			}
			else if(seq[i]==now1){
				chkmax(ans,1ll*a*(seq[i]-i)-1ll*i*c+1ll*now1*b+(now0>seq[i])*a);
			}
			else{
				if(now0>now1){
					chkmax(ans,1ll*a*(now1+1-i)-1ll*i*c+1ll*now1*b);
				}
				else if(now0<now1){
					chkmax(ans,1ll*a*(now0-i)-1ll*i*c+1ll*(now0+1)*b);
					if((vec[0].fi==0||vec.back().fi==0)&&now1>=now0+2)
						chkmax(ans,1ll*a*(now0-i)-1ll*(i+1)*c+1ll*(now0+2)*b);
					if(vec[0].fi==0&&vec.back().fi==0&&now1>=now0+3)
						chkmax(ans,1ll*a*(now0-i)-1ll*(i+2)*c+1ll*(now0+3)*b);
				}
				else{
					chkmax(ans,1ll*a*(now0-i)-1ll*i*c+1ll*now0*b);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}