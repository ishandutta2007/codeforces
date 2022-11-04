#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n<=3)
        {
            printf("-1\n");
            continue;
        }
        list<int> res={2,4,1,3};
        for(int i=5;i<=n;i++)
        {
            if(i&1)res.push_front(i);
            else res.push_back(i);
        }
        bool head=1;
        for(auto &t:res)
        {
            if(head)head=0;
            else printf(" ");
            printf("%d",t);
        }
        printf("\n");
    }
    return 0;
}