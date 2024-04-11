#include <cstdio>
#define MAXN 1000000
char v[MAXN];
inline int bun(char a){
    if(a=='('||a==')'||a=='['||a==']'||a=='<'||a=='>'||a=='{'||a=='}')
        return 1;
    return 0;
}
int main(){
  //  FILE*fi,*fout;
    int n,con,con1,con2,flag;
    char a;
  //  fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    a=fgetc(stdin);
    n=con1=con2=con=0;
    flag=0;
    while(bun(a)==1&&flag==0){
        if(a=='['||a=='<'||a=='('||a=='{'){
            v[n++]=a;
            con1++;
        }
        else{
            con2++;
            if(n==0)
                flag=1;
            else{
                n--;
                if(v[n]=='('&&a!=')')
                        con++;
                if(v[n]=='['&&a!=']')
                        con++;
                if(v[n]=='<'&&a!='>')
                        con++;
                if(v[n]=='{'&&a!='}')
                        con++;
            }
        }
        a=fgetc(stdin);
    }
    if(con1!=con2||flag==1)
        printf("Impossible");
    else
        printf("%d" ,con);
  //  fclose(fi);
   // fclose(fout);
    return 0;
}