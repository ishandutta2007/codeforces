#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5000005;
char s[MAXN];
ll cnt[MAXN>>1],cnt1[MAXN>>1],cnt2[MAXN>>1];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='I'||s[i-1]=='E'||s[i-1]=='A'
           ||s[i-1]=='O'||s[i-1]=='U'||s[i-1]=='Y'){
            cnt[min(i,n+1-i)]++;
        }
    }
    for(int i=((n+1)>>1);i>=1;i--){
        cnt1[i]=cnt1[i+1]+cnt[i];
    }
    for(int i=1;i<=((n+1)>>1);i++){
        cnt2[i]=cnt2[i-1]+cnt1[i];
    }
    double ans=0;
    for(int i=1;i<=((n+1)>>1);i++){
        ans+=cnt2[i]*(1.0/i);
        if(2*i!=n+1)ans+=cnt2[i]*(1.0/(n+1-i));
    }
    printf("%.9f",ans);
    return 0;
}