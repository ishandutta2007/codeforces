#include<cstdio>
#include<algorithm>
using namespace std;

int n,d,l, pp, qq, p, q;
int a[111];
int main(){
    scanf("%d%d%d", &n, &d, &l);
    pp=(n+1)/2;
    qq=n/2;
    if (pp-qq*l<=d && d<=pp*l-qq) {
	for (int i=0; i<n; i+=2) a[i]=1, p+=1;
	for (int i=1; i<n; i+=2) a[i]=1, q+=1;
	if (p-q<d) {
	    for (int i=0; i<n; i+=2) {
		int t=min(l-1, d-p+q);
		a[i]+=t; p+=t;
	    }
	} else if (p-q>d) {
	    for (int i=1; i<n; i+=2) {
		int t=min(l-1, p-q-d);
		a[i]+=t; q+=t;
	    }
	}
	for (int i=0; i<n; i++) printf("%d%c", a[i], i+1==n?'\n':' ');
    } else { puts("-1"); }

  return 0;
}