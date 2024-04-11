        #include<iostream>
        #include<cstdio>
        #include<algorithm>
        #include<cmath>
        using namespace std;
        const double eps=1e-6;
        int n,m,a[1010],b[1010];
        double l,r,ans;
        bool check(double x){
        	double sum=0,tmp=m+x;
        	for(int i=1;i<=n;i++){
        		sum+=tmp/a[i];tmp-=tmp/a[i];
        		sum+=tmp/b[i+1];tmp-=tmp/b[i+1];
        	}
        	return sum<x;
        }
        int main(){
        	scanf("%d%d",&n,&m);
        	for(int i=1;i<=n;i++) scanf("%d",a+i);
        	for(int i=1;i<=n;i++) scanf("%d",b+i);
        	b[n+1]=b[1];
        	l=0;r=1e9;ans=-1;
        	for(int i=1;i<=100;i++){
        		double mid=(l+r)/2;
        		if(check(mid)) ans=r=mid;
        		else l=mid;
        	}
        	if(fabs(ans+1)<eps) printf("-1");
        	else printf("%.10lf\n",ans);
        }