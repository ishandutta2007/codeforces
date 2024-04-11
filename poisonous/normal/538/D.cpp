#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int n;
char s[155][155],p[155][155],f[155][155];
int get(int i,int j)
{
    if(i<=0||j<=0||i>n||j>n||s[i][j]!='.')
        return 1;
    else
        return 0;
}
int main()
{
    cin>>n;
    int n1,n2,n3,n4;
    for(n1=1;n1<=n;n1++)
        cin>>s[n1]+1;
    for(n1=1;n1<=2*n-1;n1++)
        for(n2=1;n2<=2*n-1;n2++)
            p[n1][n2]='.';
    for(n1=1;n1<=n;n1++)
        for(n2=1;n2<=n;n2++)
            if(s[n1][n2]=='o')
                for(n3=1;n3<=n;n3++)
                    for(n4=1;n4<=n;n4++)
                        if(s[n3][n4]=='x')
                            p[n+n3-n1][n+n4-n2]='x';
    for(n1=1;n1<=2*n-1;n1++)
        for(n2=1;n2<=2*n-1;n2++)    
            if(p[n1][n2]=='x')
                for(n3=1;n3<=n;n3++)
                    for(n4=1;n4<=n;n4++)
                        if(s[n3][n4]=='o')  
                            if(get(n3+n1-n,n4+n2-n)==0)
                                p[n1][n2]='.';
    for(n1=1;n1<=2*n-1;n1++)
        for(n2=1;n2<=2*n-1;n2++)    
            if(p[n1][n2]=='x')
                for(n3=1;n3<=n;n3++)
                    for(n4=1;n4<=n;n4++)
                        if(s[n3][n4]=='o')
                            if(n3+n1-n>0&&n4+n2-n>0)
                                f[n3+n1-n][n4+n2-n]='x';
    for(n1=1;n1<=n;n1++)
        for(n2=1;n2<=n;n2++)
            if(s[n1][n2]=='x'&&f[n1][n2]!='x')
            {
                cout<<"NO";
                return 0;
            }
    p[n][n]='o';
    cout<<"YES\n";
    for(n1=1;n1<=2*n-1;n1++)
        p[n1][2*n]=0;
    for(n1=1;n1<=2*n-1;n1++)
        cout<<p[n1]+1<<endl;    
                                        
}