#include <bits/stdc++.h>
using namespace std;
const int MX=200200,MM=35,LIM=10,MSK=(1<<LIM)-1,md=998244353;
int n,m,mm,low,i,j,k,cnt[MSK+5][MM+5],b[(1<<25)+5];
long long a[MX],ra[MM+5],rb[MM+5],r[MM+5],mn;
bool u[MX];
void rec(int l, int ma, int mb) {
  if (l==low) {
    //printf("cnt %d %d\n",mb,b[ma]);
    cnt[mb][b[ma]]++;
    return;
  }
  rec(l+1,ma,mb);
  rec(l+1,ma^ra[l],mb^rb[l]);
}
void rec2(int l, int msk) {
  if (l==m) {
    //printf("rec2 %d\n",msk);
    for (int j=0; j<=MSK; j++) for (int k=0; k<=MM-LIM; k++) if (cnt[j][k]) {
      int d=b[msk^j]+k;
      r[d]+=cnt[j][k];
      if (r[d]>=md) r[d]-=md;
    }
    return;
  }
  rec2(l+1,msk);
  rec2(l+1,msk^rb[l]);
}
int main() {
  scanf("%d%d",&n,&mm);
  for (i=0; i<n; i++) scanf("%I64d",&a[i]);
  for (low=-1, j=mm-1; j>=0; j--) {
    for (i=0; i<n; i++) if (!u[i] && ((a[i]>>j)&1)) {
      u[i]=true;
      if (j<LIM && low==-1) low=m;
      ra[m]=(a[i]>>LIM);
      rb[m++]=(a[i]&MSK);
      //printf("%I64d\n",a[i]);
      for (k=i+1; k<n; k++) if (!u[k] && ((a[k]>>j)&1)) a[k]^=a[i];
    }
  }
  //printf("%d\n",low);
  //for (i=0; i<n; i++) printf("%I64d, ",a[i]); puts("");
  //for (i=0; i<m; i++) printf("(%I64d %I64d), ",ra[i],rb[i]); puts("");
  if (low==-1) low=m;
  mn=1;
  for (i=0; i<n-m; i++) mn=(mn+mn)%md;
  for (i=0; i<(1<<(MM-LIM)); i++) b[i]=b[i/2]+(i&1);
  rec(0,0,0);
  rec2(low,0);
  for (i=0; i<=mm; i++) printf("%d ",int((mn*r[i])%md));
  return 0;
}