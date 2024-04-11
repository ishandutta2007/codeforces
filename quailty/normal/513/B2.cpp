#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
deque<int>ans;
int main()
{
    int n;
    long long m;
    scanf("%d%I64d",&n,&m);
    ans.push_back(n);
    m--;
    for(int i=n-1;i>=1;i--){
        if(m&1)ans.push_back(i);
        else ans.push_front(i);
        m=(m>>1);
    }
    deque<int>::iterator itr;
    for(itr=ans.begin();itr!=ans.end();itr++){
        printf("%d ",*itr);
    }
    return 0;
}