#include <cstdio>
int n, m, ans, p, a[2001], b[2001];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    if(a[i]<=m) b[a[i]]++;
    }
	for(int i=1;i<=m;i++)
        while(b[i]<n/m)
            for(int j=0; j<n&&b[i]<n/m; j++){
                if(a[j]>m){
                    p=j+1;
                    a[j]=i;
                    b[i]++;
                    ans++;
                }else if(b[a[j]]>n/m){
                    p=j+1;
                    b[a[j]]--;
                    a[j]=i;
                    b[i]++;
                    ans++;
                }
            }
	printf("%d %d\n", n/m, ans);
	for(int i=0; i<n; i++) printf("%d ",a[i]);
	putchar('\n');
	return 0;
}