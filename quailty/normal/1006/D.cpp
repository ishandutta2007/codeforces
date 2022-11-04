#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char A[MAXN],B[MAXN];
int main()
{
    int n;
    scanf("%d%s%s",&n,A+1,B+1);
    int res=0;
    for(int i=1,j=n;i<j;i++,j--)
    {
        int now=min((A[i]!=B[i])+(A[j]!=B[j]),(A[i]!=B[j])+(A[j]!=B[i]));
        if(B[i]==B[j])now=min(now,(int)(A[i]!=A[j]));
        res+=now;
    }
    res+=(n%2==1 && A[(n+1)/2]!=B[(n+1)/2]);
    printf("%d\n",res);
    return 0;
}