#include<bits/stdc++.h>
#define N 200010
#define M 2000010
#define mod 1000000007
#define mp make_pair
#define PII pair<int,int>
using namespace std;
int n,m,i,j,ans;
char s[200010];
int main()
{
    scanf("%d%s",&n,s+1);
    for(i=1;i<=n;i++)
        ans+=s[i]-'0';
    printf("%d\n",abs(n-ans-ans));
}