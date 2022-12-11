#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define fore(i,a,n) for(int i = a,qwer=n;i<qwer;i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 100500;
ll a[N];
int main() {
	int n,n1,n2;
	scanf("%d%d%d",&n,&n1,&n2);
	fore(i,0,n)
		scanf("%I64d",a+i);
	sort(a,a+n);
	ll s = 0,t = 0;
	if(n1 > n2)	swap(n1,n2);
	for(int i = 0;i<n1;i++)
		s += a[n-1-i];
	fore(i,0,n2)
		t += a[n-1-n1-i];
	
	double ans = s;
	ans /= n1;
	ans += ((double)t)/n2;
	printf("%.15lf\n",ans);
}