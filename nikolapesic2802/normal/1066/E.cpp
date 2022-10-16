#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=3*1e5;
vector<int> stepeni(N);
const int mod=998244353;
int main()
{
   // ios_base::sync_with_stdio(0);
    //cin.tie(nullptr);
    stepeni[0]=1;
    for(int i=1;i<N;i++)
    {
        stepeni[i]=(stepeni[i-1]*2)%mod;
    }
    int n,m;
    scanf("%i %i",&n,&m);
    int tr=n-m;
    int sum=0;
    char s1[n+1],s2[m+1];
    scanf("%s",s1);
    scanf("%s",s2);
    //string s1,s2;
    //cin >> s1 >> s2;
    int res=0;
    for(int i=0;i<m;i++)
    {
        if(s2[i]=='1')
        {
            sum++;
        }
        if(tr>=0)
        {
            if(s1[tr]=='1')
            {
                res=((ll)res+(ll)sum*stepeni[n-tr-1])%mod;
            }
        }
        tr++;
    }
    printf("%i\n",res);
    return 0;
}