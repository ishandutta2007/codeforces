#include<bits/stdc++.h>
#define MAXN 1000010
#define LL long long
using namespace std;
string s;
int a[10],ans;
int main(){
    cin>>s;
    for (int i=0;i<s.length();i++){
        if (s[i]=='B') a[0]++;
        else if (s[i]=='u') a[1]++;//2
        else if (s[i]=='l') a[2]++;
        else if (s[i]=='b') a[3]++;
        else if (s[i]=='a') a[4]++;//2
        else if (s[i]=='s') a[5]++;
        else if (s[i]=='r') a[6]++;
    }
    ans=s.length();
    for (int i=0;i<7;i++) ans=min(ans,a[i]);
    ans=min(ans,a[1]/2);
    ans=min(ans,a[4]/2);
    printf("%d\n",ans);
}