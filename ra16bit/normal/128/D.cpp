    #include <stdio.h>
    int n,i,mn,mx,a[100100],b[100100],c[100100];
    int main() {
      scanf("%d",&n);
      for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if (i==0 || a[i]<mn) mn=a[i];
        if (i==0 || a[i]>mx) mx=a[i];
      }
      if (n%2==1 || mx>mn+100010) { puts("NO"); return 0; }
      mn--; mx-=mn;
      for (i=0; i<n; i++) b[a[i]-mn]++;
      //for (i=1; i<=mx; i++) if ((i>1 && i<mx && b[i]<2) || b[i]>b[i-1]+b[i+1]) { puts("NO"); return 0; }
      //if (mx>2 && (b[1]>=b[2] || b[mx]>=b[mx-1])) { puts("NO"); return 0; }
      c[1]=b[1];
      for (i=2; i<mx; i++) {
        c[i]=b[i]-c[i-1];
        if (c[i]<=0) { puts("NO"); return 0; }
      }
      if (b[i]-c[i-1]!=0) puts("NO"); else puts("YES");
      return 0;
    }