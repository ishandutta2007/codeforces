#include <cstdio>

char h[2][100010];
int hc[2][26];
int cnt[26];
char buf[100010];

int min(int a,int b) { return a>b?b:a; }

int main()
{
    int i,j;
    scanf("%s",buf);
    for(i=0;buf[i];++i) ++cnt[buf[i]-'a'];
    scanf("%s%s",h[0],h[1]);
    for(i=0;i<2;++i) for(j=0;h[i][j];++j) ++hc[i][h[i][j]-'a'];
    int mv=-1, mi=-1;
    int cc;
    for(i=0;i<=100000;++i){
        cc=2e9;
        for(j=0;j<26;++j){
            if(i*hc[0][j]>cnt[j]) break;
            if(hc[1][j]) cc=min(cc,(cnt[j]-i*hc[0][j])/hc[1][j]);
        }
        if(j!=26) break;
        cc+=i;
        if(mv<cc) mv=cc, mi=i;
    }
    for(i=0;i<mi;++i) printf("%s",h[0]);
    for(i=mi;i<mv;++i) printf("%s",h[1]);
    //printf("mi %d mv %d\n",mi,mv);
    for(i=0;i<26;++i){
        cnt[i]-=mi*hc[0][i]+(mv-mi)*hc[1][i];
        for(j=cnt[i];j--;) putchar('a'+i);
    }
    return 0;
}