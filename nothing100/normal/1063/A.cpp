#include<bits/stdc++.h>
using namespace std;
int n;
char ch[100010];
int main(){
    scanf("%d",&n);
    scanf("%s",ch);
    sort(ch,ch+n);
    printf("%s",ch);
}