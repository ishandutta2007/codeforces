#include<bits/stdc++.h>
#define MAXN 500010
#define inf 1e+15
using namespace std;
char s[2000],ss[2000];
int ma[30],ans;
int main(){
    scanf("%s%s",s,ss);
    for (int i=0;i<strlen(s);i++){
        if (ma[s[i]-'a'+1]==0&&ma[ss[i]-'a'+1]==0){
            ma[s[i]-'a'+1]=ss[i]-'a'+1;
            ma[ss[i]-'a'+1]=s[i]-'a'+1;
            if (s[i]-'a'+1!=ss[i]-'a'+1) ans++;
        }
        else if (ma[s[i]-'a'+1]!=ss[i]-'a'+1||ma[s[i]-'a'+1]!=ss[i]-'a'+1){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<27;i++)
    if (ma[i]>i){
        printf("%c %c\n",'a'+i-1,'a'+ma[i]-1);
    }
}