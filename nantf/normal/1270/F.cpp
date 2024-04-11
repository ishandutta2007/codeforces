#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,maxx=90000000;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,sq,pre[maxn],lft[maxn],rig[maxn],cnt,buc[maxx];
ll ans;
char s[maxn];
int main(){
	scanf("%s",s+1);
	sq=sqrt(n=strlen(s+1));
	FOR(i,1,n) pre[i]=pre[i-1]+(s[i]=='1');
	FOR(i,0,n) if(!i || pre[i]!=pre[i-1]) rig[cnt]=i-1,lft[++cnt]=i;
	rig[cnt]=n;
	FOR(i,1,sq){
		FOR(j,0,n){
			ans+=buc[j-i*pre[j]+sq*n];
			buc[j-i*pre[j]+sq*n]++;
		}
		FOR(j,0,n) buc[j-i*pre[j]+sq*n]--;
	}
	FOR(i,1,cnt) FOR(j,i+1,min(i+n/sq,cnt)){
		int l=rig[j-1]-lft[i+1]+1,a=rig[i]-lft[i]+1,b=rig[j]-lft[j]+1;
		if(a>b) swap(a,b);
		int fst,lst;
		if(l+1<=l+a){
			fst=l+1+(j-i-(l+1)%(j-i))%(j-i);
			lst=l+a-(l+a)%(j-i);
			fst=max(fst,(j-i)*(sq+1));
			if(fst<=lst){
				fst-=l;lst-=l;
				ans+=1ll*(fst+lst)*((lst-fst)/(j-i)+1)/2;
			}
		}
		if(l+a+1<=l+b){
			fst=l+a+1+(j-i-(l+a+1)%(j-i))%(j-i);
			lst=l+b-(l+b)%(j-i);
			fst=max(fst,(j-i)*(sq+1));
			if(fst<=lst){
				ans+=1ll*a*((lst-fst)/(j-i)+1);
			}
		}
		if(l+b+1<=l+a+b){
			fst=l+b+1+(j-i-(l+b+1)%(j-i))%(j-i);
			lst=l+a+b-(l+a+b)%(j-i);
			fst=max(fst,(j-i)*(sq+1));
			if(fst<=lst){
				swap(fst,lst);
				fst=l+a+b-fst;lst=l+a+b-lst;
				ans+=1ll*(fst+lst)*((lst-fst)/(j-i)+1)/2;
			}
		}
	}
	printf("%lld\n",ans);
}