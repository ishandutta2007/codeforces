#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int a[2*n+2][2*n+2];
	int last[2*n+1];
	
	for (int i=1;i<=2*n+1;i++)
	{ if (i>n+1) a[i][n+1]=2*(n+1)-i-1; else a[i][n+1]=i-1;
	  last[i]=2*n+1;
	 for (int j=n+2;j<=2*n+1;j++)
        {a[i][j]=a[i][j-1]-1;if (a[i][j]==0) last[i]=j;}		 
	 for (int j=n;j>=1;j--)
        a[i][j]=a[i][j+1]-1;		 
	}
	last[1]=n+1; last[2*n+1]=n+1;
	
	for (int i=1;i<=2*n+1;i++) {
      for (int j=1;j<=2*n+1;j++)
        {if (a[i][j]>=0&j<last[i]) printf("%d ",a[i][j]); else if (j==last[i]) printf("%d",a[i][j]); else if (j<=last[i]) printf("  ");}
      printf("\n");
	}		
		
		
		
    return 0;
}