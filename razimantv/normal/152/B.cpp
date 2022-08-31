# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>

using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    
    int x,y;
    scanf("%d%d",&x,&y);
    
    long long cnt=0;
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        
        int add=1000000000;
        if(a>0)add=min(add,(N-x)/a);
        else if(a<0)add=min(add,(x-1)/-a);
        if(b>0)add=min(add,(M-y)/b);
        else if(b<0)add=min(add,(y-1)/(-b));
        cnt+=add;
        x+=add*a;
        y+=add*b;
    }
    cout<<cnt<<endl;
    return 0;
}