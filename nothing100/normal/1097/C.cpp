#include<bits/stdc++.h>
using namespace std;
int n;
char ch[500050];
int l[500050],r[500050],ans;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s",ch);
        int ll=0,rr=0,len=strlen(ch);
        for (int j=0;j<len;j++)
        if (ch[j]=='(') ll++;
        else{
            if (ll>0) ll--;
            else rr++;
        }
        if (ll==0) r[rr]++;
        else if (rr==0) l[ll]++;
    }
    for (int i=1;i<=500000;i++) ans+=min(l[i],r[i]);
    ans+=r[0]/2;
    printf("%d\n",ans);
}