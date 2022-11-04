#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],b[200005];
int main()
{
    int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int cnt=0;
	b[cnt++]=a[0];
	for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
			b[cnt++]=a[i];
		}
	}
	int ans=0;
	for(int i=0;i<cnt;i++){
        int val=b[i],j=i;
        while(j<cnt){
            val+=b[i];
            j=lower_bound(b,b+cnt,val)-b;
            ans=max(ans,b[j-1]%b[i]);
        }
	}
	printf("%d\n", ans);
	return 0;
}