#include <bits/stdc++.h>
inline bool check(int a,int b) {
    if(a/10==b%10&&a%10==b/10)
      return 1;
    return 0;
}
int main() {
    FILE * fi, * fout;
    int a,b;
    char ch;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%c%d" ,&a,&ch,&b);
    int cnt=0;
    while(!check(a,b)) {
        b++;
        cnt++;
        if(b==60) {
          a++;
          b=0;
        }
        if(a==24)
          a=0;
    }
    fprintf(fout,"%d" ,cnt);
    //fclose(fi);
    //fclose(fout);
    return 0;
}