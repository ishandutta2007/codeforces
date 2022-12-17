#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=4e4+5;
int n,m,k;
bool a[maxn],b[maxn];
int s1[maxn],s2[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    m=readint();
    k=readint();
    for(int i=0;i<n;i++) a[i]=readint();
    for(int i=0;i<m;i++) b[i]=readint();
    int l=0;
    for(int i=0;i<n;i++){
    	if(a[i]) l++;
    	else l=0;
    	s1[l]++;
	}
	for(int i=n;i>0;i--) s1[i]+=s1[i+1];
    l=0;
    for(int i=0;i<m;i++){
    	if(b[i]) l++;
    	else l=0;
    	s2[l]++;
	}
	for(int i=m;i>0;i--) s2[i]+=s2[i+1];
	long long ans=0;
	for(int i=1;1ll*i*i<=k;i++) if(k%i==0){
		if(k/i<=m) ans+=1ll*s1[i]*s2[k/i];
		if(i*i<k&&k/i<=n) ans+=1ll*s1[k/i]*s2[i];
	}
	printf("%lld\n",ans);
    return 0;
}