#include<cctype>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=300000,inf=0x3f3f3f3f;
int a[maxn+10],n; char c[maxn+10];
int b[maxn+10],bcnt,maxr,minr=inf,maxb,minb=inf,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(c[i]=getchar();!isgraph(c[i]);c[i]=getchar());
		if(c[i]=='G') b[++bcnt]=i;
		else if(c[i]=='R'){
			maxr=max(maxr,a[i]); minr=min(minr,a[i]);
		}else if(c[i]=='B'){
			maxb=max(maxb,a[i]); minb=min(minb,a[i]);
		}
	}
	if(bcnt==0){
		if(maxr) ans+=maxr-minr;
		if(maxb) ans+=maxb-minb;
	}else{
		if(minr<a[b[1]]) ans+=a[b[1]]-minr;
		if(maxr>a[b[bcnt]]) ans+=maxr-a[b[bcnt]];
		if(minb<a[b[1]]) ans+=a[b[1]]-minb;
		if(maxb>a[b[bcnt]]) ans+=maxb-a[b[bcnt]];
		for(int i=1;i<bcnt;++i){
			int prer=a[b[i]],preb=a[b[i]],maxr=0,maxb=0;
			for(int j=b[i]+1;j<b[i+1];++j)
				if(c[j]=='R'){
					maxr=max(maxr,a[j]-prer); prer=a[j];
				}else{
					maxb=max(maxb,a[j]-preb); preb=a[j];
				}
			maxr=max(maxr,a[b[i+1]]-prer); maxb=max(maxb,a[b[i+1]]-preb);
			if(maxr+maxb>a[b[i+1]]-a[b[i]]) ans+=(a[b[i+1]]-a[b[i]])*3ll-maxr-maxb;
			else ans+=(a[b[i+1]]-a[b[i]])*2;
		}
	}
	printf("%d",ans);
}