#include<cstdio>
#include<algorithm>
using namespace std;
int n, a[111];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    if (n<3 || n%2==0) puts("-1");
    else {
	int ans=0;
	for (int i=n/2-1; i>=0; i--) {
	    int p=i*2+1, q=i*2+2, m;
	    m=max(a[p], a[q]);
	    ans+=m;
	    a[p]=a[q]=0;
	    a[i]=max(0, a[i]-m);
	}
	ans+=a[0];
	printf("%d\n", ans);
    }
    return 0;
}