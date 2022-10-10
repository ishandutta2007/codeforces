#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,j,it,ii,cnt,prv,who,b[402],c[402],f[402],u[402],F[402][402],pra[402],prb[402],ua[402],ub[402];
pair<int,int> a[402];
vector<int> qa,qb,nqa,nqb;
double d[402][402],pa[402],pb[402],nc,cost,best,eps=1e-10;
double sqr(double x) { return x*x; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].second,&a[i].first);
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i++) {
    for (b[i]=i+1; b[i]<n; b[i]++) if (a[i].first>a[b[i]].first) break;
	for (c[i]=i-1; c[i]>=0; c[i]--) if (a[c[i]].first>a[i].first) break;
  }
  for (i=0; i<n; i++) for (j=0; j<n; j++) d[i][j]=sqrt(sqr(a[i].first-a[j].first)+sqr(a[i].second-a[j].second));
  for (cnt=1; cnt<n; cnt++) {
    qa.clear();
	qb.clear();
    for (i=0; i<n; i++) {
	  if (f[i]<2) {
	    pa[i]=0;
		qa.push_back(i);
      } else pa[i]=1e11;
	  pb[i]=1e11;
	  ua[i]=0;
	  ub[i]=0;
	}
	best=1e10; who=-1;
    for (it=1; it<=n+n; it++) {
	  nqa.clear();
      nqb.clear();
	  for (ii=0; ii<qa.size(); ii++) {
	    i=qa[ii];
		for (j=b[i]; j<n; j++) if (F[i][j]<1) {
		  nc=pa[i]+d[i][j];
		  if (nc<pb[j]-eps) {
		    pb[j]=nc;
			prb[j]=i;
			if (ub[j]!=it) {
			  ub[j]=it;
			  nqb.push_back(j);
			}
		  }
		}
	  }
	  for (ii=0; ii<qb.size(); ii++) {
	    i=qb[ii];
		for (j=0; j<=c[i]; j++) if (F[j][i]>0) {
		  nc=pb[i]-d[i][j];
		  if (nc<pa[j]-eps) {
		    pa[j]=nc;
			pra[j]=i;
			if (ua[j]!=it) {
			  ua[j]=it;
			  nqa.push_back(j);
			}
		  }
		}
	  }
	  qa=nqa;
	  qb=nqb;
	}
	for (i=0; i<n; i++) if (u[i]<1 && pb[i]<best) { best=pb[i]; who=i; }
	if (who<0) { puts("-1"); return 0; }
	cost+=best;
	u[who]++;
	while (true) {
	  prv=prb[who];
	  F[prv][who]++;
	  if (f[prv]<2) {
	    f[prv]++;
	    break;
      }
	  who=pra[prv];
	  F[prv][who]--;
	}
  }
  printf("%.15lf\n",cost);
  return 0;
}