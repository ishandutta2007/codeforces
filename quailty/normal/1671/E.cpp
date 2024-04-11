#include<bits/stdc++.h>
using namespace std;
const int MAXN=18;
const int MAXL=(1<<MAXN)+5;
const int Mod=998244353;
char str[MAXL];
string solve(int n,int d,int& res)
{
    if(d==1)return string(str[n],1);
    string lef=solve(2*n,d-1,res);
    string rig=solve(2*n+1,d-1,res);
    if(lef!=rig)res=res*2%Mod;
    return min(lef+str[n]+rig,rig+str[n]+lef);
}
int main()
{
    int n,res=1;
    scanf("%d%s",&n,str+1);
    solve(1,n,res);
    return 0*printf("%d\n",res);
}