#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,sum=0;
    vector<int>res;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(sum+i>n)break;
        res.push_back(i);
        sum+=i;
    }
    res.back()+=n-sum;
    cout<<(int)res.size()<<endl;
    for(int i=0;i<(int)res.size();i++)
        cout<<res[i]<<" \n"[i+1==(int)res.size()];
    return 0;
}