#include <cstdio>
#include <set>
using namespace std;
int n,k,i,j,res,c,a[200000],x[200000],y[200000];
multiset <int> e;
int main() {
	scanf("%d%d",&n,&k);
	for (i=0; i<n; i++) scanf("%d",&a[i]);
	for (i=j=0; i<n; i++) {
		e.insert(a[i]);
		multiset<int>::iterator ll=e.begin();
		multiset<int>::iterator rr=e.end(); rr--;
		while ((*rr)-(*ll)>k) {
			e.erase(e.find(a[j])); j++;
			ll=e.begin();
		    rr=e.end(); rr--;
		}
		if (i-j+1>res) { res=i-j+1; c=0; }
		if (i-j+1==res) { c++; x[c]=j+1; y[c]=i+1; }
	}
	printf("%d %d\n",res,c);
	for (i=1; i<=c; i++) printf("%d %d\n",x[i],y[i]);
	return 0;
}