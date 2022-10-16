#include <bits/stdc++.h>
int n,m,s=1,c,a;
int main()
{
    std::cin>>n;
    while(n--)
    {
        std::cin>>a;
        if(a>m)
            m=a,s=1,c=0;
        if(a==m)
            c++;
        else
            c=0;
        s=std::max(s,c);
    }
    std::cout<<s;
}