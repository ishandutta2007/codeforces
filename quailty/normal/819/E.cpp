#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int> > cir;
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2)
    {
        cir.push_back(vector<int>{1,2,3});
        cir.push_back(vector<int>{1,2,3});
    }
    else
    {
        cir.push_back(vector<int>{1,2,3});
        cir.push_back(vector<int>{1,2,4});
        cir.push_back(vector<int>{1,3,4});
        cir.push_back(vector<int>{2,3,4});
    }
    for(int i=6-(n%2);i<=n;i+=2)
    {
        cir.push_back(vector<int>{i-1,i,i-2});
        cir.push_back(vector<int>{i-1,i,i-2});
        for(int j=1,p=1,q=2;j<=i-3;j++,p=(p+1)%(i-3)+1,q=(q+1)%(i-3)+1)
            cir.push_back(vector<int>{i-1,p,i,q});
    }
    printf("%d\n",(int)cir.size());
    for(int i=0;i<(int)cir.size();i++)
    {
        printf("%d",(int)cir[i].size());
        for(int j=0;j<(int)cir[i].size();j++)
            printf(" %d",cir[i][j]);
        printf("\n");
    }
    return 0;
}