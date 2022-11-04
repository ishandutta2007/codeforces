#include <cstdio>
#define MAXN 1000000
int v1[MAXN],v2[MAXN];
char a;
inline void cit(){
    while(a=='0')
        a=fgetc(stdin);
}
int main(){
    int n,m;
    a=fgetc(stdin);
    cit();
    n=0;
    while(a>='0'&&a<='9'){
        v1[n++]=a;
        a=fgetc(stdin);
    }
    m=0;
    a=fgetc(stdin);
    cit();
    while(a>='0'&&a<='9'){
        v2[m++]=a;
        a=fgetc(stdin);
    }
    if(n>m)
        printf(">");
    else
        if(n<m)
            printf("<");
        else
          if(n==m){
            int i=0;
            while(i<n&&v1[i]==v2[i])
               i++;
            if(i==n)
                printf("=");
            else
                if(v1[i]>v2[i])
                   printf(">");
                else
                    printf("<");
          }
    return 0;
}