#include <bits/stdc++.h>
inline int sum(long long n) {
    int ans = 0;
    while(n > 0) {
       ans += n % 10;
       n /= 10;
    }
    return ans;
}
int main() {
    FILE * fi, * fout;
    long long n,s;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%I64d%I64d" ,&n,&s);
    long long cnt = 0;
    for(int i=0;i<=2000000&&s+i<=n;i++)
      if(s+i-sum(s+i) >= s)
         cnt++;
    if(s+2000000<n)
      cnt += n-(s+2000000);
    fprintf(fout,"%I64d" ,cnt);
    //fclose(fi);
    //fclose(fout);
    return 0;
}