#include<bits/stdc++.h>
using namespace std;
char ch[10][5];
int main(){
    for (int i=0;i<6;i++) scanf("%s",ch[i]);
    for (int i=1;i<6;i++)
    if (ch[i][0]==ch[0][0]||ch[i][1]==ch[0][1]){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
}