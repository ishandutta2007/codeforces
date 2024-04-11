#include <cstdio>
#include <vector>
using namespace std;
const double inf=1e13;
int i,ii,j,k,l,n,r,cnt2,best=3,fi,qq,wp[11],b[11],c[11],mask[11],s[11],sum[1<<11],f[2200000];
vector<int> q[444];
long long a[11],w[1<<11],cur,x;
bool ee,wr;
void upd(int z, int cost) {
  if ((cost<f[z] || f[z]==0) && cost<=best) {
    f[z]=cost;
	q[cost].push_back(z);
  }
}
void add(int cost) {
if (wr) printf("cost %d:\n",cost);
if (wr) { for (int p=0; p<n; p++) printf("%d ",c[p]);puts(""); }
  for (int p=0; p<11; p++) wp[p]=0;
  int cnt=2,z=0;
  for (int p=0; p<n; p++) if (c[p]>1) {
  if (wr) printf("%d %d %d\n",c[p],wp[c[p]],cnt);
    if (wp[c[p]]==0) wp[c[p]]=cnt++;
	if (wr) printf("%d %d %d~\n",c[p],wp[c[p]],cnt);
	c[p]=wp[c[p]];
  }
if (wr) { for (int p=0; p<n; p++) printf("%d ",c[p]);puts("");}
  for (int p=n-1; p>=0; p--) z=z*(p+3)+c[p];
  if (wr)printf("===> %d\n",z);
  upd(z,cost);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d",&a[i]);
	cur=a[i];
	for (x=2; x*x<=cur; x++) while (cur%x==0) { s[i]++; cur/=x; }
	if (cur>1) s[i]++;
	best+=s[i]+1;
  }
  w[0]=1;
  for (i=1; i<(1<<n); i++) {
    for (j=0; j<n; j++) if (i&(1<<j)) {
	  double z1=w[i^(1<<j)],z2=a[j];
	  if (z1*z2>inf) w[i]=inf; else w[i]=w[i^(1<<j)]*a[j];;
	  sum[i]=sum[i^(1<<j)]+s[j];
	  //printf("%d --> %d %d\n",i,int(w[i]),sum[i]);
	  break;
	}
  }
  for (i=n-1; i>=0; i--) r=r*(i+3)+1;
  f[0]=1; q[1].push_back(0);
  for (qq=1; qq<=best; qq++) for (fi=0; fi<q[qq].size(); fi++) {
    ii=i=q[qq][fi];
	if (f[i]!=qq) continue;
	//printf("%d = %d\n",i,qq);
	if (i==r) { printf("%d\n",f[r]-1); return 0; }
	for (j=0; j<n+3; j++) mask[j]=0;
	for (j=cnt2=0; j<n; j++) {
	  b[j]=ii%(j+3);
	  ii/=j+3;
	  mask[b[j]]|=1<<j;
	  //printf("%d ",b[j]);
	  if (b[j]>1) cnt2++;
	}
	//puts("~~~");
	wr=false;
	//if (b[3]==2) wr=true;
	ee=true;
	for (j=0; j<n; j++) if (b[j]==0) {
	  for (l=0; l<n; l++) if (j==l) c[l]=10; else c[l]=b[l];
	  add(f[i]+s[j]+int(s[j]>1));
	  ee=false;
	}
	if (ee) {
	  upd(r,f[i]+int(cnt2>1));
	}
	for (j=2; j<n+3 && mask[j]>0; j++) {
	  if (wr) printf("-> %d %d %d\n",j,mask[j],int(w[mask[j]]));
	  for (k=0; k<n; k++) if (b[k]==0 && a[k]%w[mask[j]]==0) {
	    if (wr) printf("k is %d\n",k);
	    for (l=0; l<n; l++) if (k==l) c[l]=10;
		  else if (b[l]==j) c[l]=1; else c[l]=b[l];
	    add(f[i]+s[k]-sum[mask[j]]+1);
	  }
	  for (k=j+1; k<n+3 && mask[k]>0; k++) {
	    for (l=0; l<n; l++) if (b[l]==k) c[l]=j; else c[l]=b[l];
	    add(f[i]);
      }
	}
	if (wr) puts("end");
  }
  printf("%d\n",f[r]-1);
  return 0;
}