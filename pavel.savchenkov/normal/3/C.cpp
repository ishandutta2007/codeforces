#include <cstdio>
#include <algorithm>
using namespace std;

char a[5][5];

bool checkwin(char c){
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++){
        if(a[i][j]!=c) continue;
        if(a[i-1][j-1]==c && a[i+1][j+1]==c) return true;
        if(a[i-1][j+0]==c && a[i+1][j+0]==c) return true;
        if(a[i-1][j+1]==c && a[i+1][j-1]==c) return true;
        if(a[i+0][j-1]==c && a[i+0][j+1]==c) return true;
    }
    return false;
}

int getcount(char c){
    int ret=0;
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) ret+=(a[i][j]==c);
    return ret;
}

int main(){
    for(int i=1;i<=3;i++) scanf("%s",a[i]+1);
    bool x=checkwin('X');
    bool o=checkwin('0');
    int sx=getcount('X');
    int so=getcount('0');
    if(sx<so || sx>so+1) return puts("illegal");
    if(sx+so==9 && !o && !x) return puts("draw");
    if(sx!=so && o || sx==so && x) return puts("illegal");
    if(sx!=so && x) return puts("the first player won");
    if(sx==so && o) return puts("the second player won");
    if(sx==so) return puts("first");
    if(sx!=so) return puts("second");
}