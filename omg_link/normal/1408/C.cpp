#include <stdio.h>
#define MN 100000

int n,l,a[MN+5];
double t[2][MN+5];

void solve(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1] = l;
	t[0][0] = 0;
	for(int i=1,v=1;i<=n+1;i++){
		t[0][i] = t[0][i-1] + double(a[i]-a[i-1])/v;
		v++;
	}
	t[1][n+1] = 0;
	for(int i=n,v=1;i>=0;i--){
		t[1][i] = t[1][i+1] + double(a[i+1]-a[i])/v;
		v++;
	}
	for(int i=0;i<=n;i++){
		if(t[0][i]<=t[1][i]&&t[0][i+1]>=t[1][i+1]){
			double t0 = t[0][i];
			double t1 = t[1][i+1];
			double s = (a[i+1]-a[i]);
			int v0 = i+1;
			int v1 = n-i+1;
			if(t0<t1){
				s -= (t1-t0)*v0;
				t0 = t1;
			}else{
				s -= (t0-t1)*v1;
				t1 = t0;
			}
			t0 += s/(v0+v1);
			printf("%.10lf\n",t0);
			break;
		}
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}