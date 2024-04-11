#include <cstdio>
#define MAXN 50000
char v[MAXN+1];
int vf[26];
int main(){
    char a=fgetc(stdin);
    int i,j,n,p,flag;
    n=0;
    while(a=='?'||(a>='A'&&a<='Z')){
        v[++n]=a;
        a=fgetc(stdin);
    }
    if(n<26)
          printf("-1");
    else{
        flag=0;
        for(i=1;i<=n-25;i++){
            for(j=0;j<26;j++)
              vf[j]=0;
            for(j=0;j<26;j++)
              if(v[j+i]!='?')
                vf[v[j+i]-'A']++;
            j=0;
            while(j<26&&vf[j]<2)
              j++;
            if(j==26){
                p=0;
                for(j=0;j<26;j++)
                  if(v[j+i]=='?'){
                      while(p<26&&vf[p]!=0)
                        p++;
                      v[j+i]='A'+p;
                      p++;
                  }
                flag=1;
            }
        }
        if(flag==0)
             printf("-1");
        else{
             for(i=1;i<=n;i++){
               if(v[i]=='?')
                 v[i]='A';
                 printf("%c" ,v[i]);
             }
        }
    }
    return 0;
}