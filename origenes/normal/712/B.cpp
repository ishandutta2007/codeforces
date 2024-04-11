#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char s[100010]="";
int main(){
    scanf("%s", s);
    int len=strlen(s);
    if(len&1){
        printf("-1\n");
        return 0;
    }
    int lw=0, ud=0;
    for(int i=0; i<len; i++){
        if(s[i]=='L') lw++;
        else if(s[i]=='R') lw--;
        else if(s[i]=='U') ud++;
        else ud--;
    }
    int count=0;
    lw=abs(lw);
    ud=abs(ud);
    if(lw&1){
        count=1+lw/2+ud/2;
    }
    else count=lw/2+ud/2;
    printf("%d\n", count);
    return 0;
}