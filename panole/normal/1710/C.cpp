#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,f[200010][2][2][2];
char s[200010];

void add(int &a,int b) {a=(a+b>=mod?a+b-mod:a+b);}

int main()
{
    scanf("%s",s+1),n=strlen(s+1);
    f[0][1][1][1]=1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<2; l++) if (f[i-1][j][k][l])
                    for (int nj=0; nj<=(s[i]=='1'||j==0); nj++)
                        for (int nk=0; nk<=(s[i]=='1'||k==0); nk++)
                            for (int nl=0; nl<=(s[i]=='1'||l==0); nl++)
                                if (nj==nl||nk==nl)
                                    add(f[i][j&(nj==(s[i]-'0'))][k&(nk==(s[i]-'0'))][l&(nl==(s[i]-'0'))],f[i-1][j][k][l]);
    int ans=0;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++) 
            for (int k=0; k<2; k++) add(ans,f[n][i][j][k]);
    int cnt3=0,cnt2,Ans;
    for (int i=1; i<=n; i++) cnt3=(2ll*cnt3+(s[i]-'0'))%mod;
    cnt3=(cnt3+1)%mod;
    Ans=1ll*cnt3*cnt3%mod*cnt3%mod;
    cnt2=1ll*cnt3*(cnt3-1)%mod;
    ans=(ans-cnt3-2ll*cnt2+10ll*mod)%mod;
    Ans=(Ans-3ll*ans-3ll*cnt2-cnt3+10ll*mod)%mod;
    printf("%d\n",Ans);
    return 0;
}
// a^b + b^c = a^c
// a^b & b^c = 0
// a & c \subset b \subset a | c

//b =  2^popcount(a xor c)