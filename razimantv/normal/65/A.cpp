# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>
# include <queue>

using namespace std;
    
int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    
    int s1=a*c*e,s2=b*d*f;
    if(s1>0||s2>0)
    {
        if(s1<s2)printf("Ron\n");
        else printf("Hermione\n");
    }
    else if(d==0)printf("Hermione\n");
    else if(c==0)printf("Ron\n");
    else if(b==0)printf("Hermione\n");
    else if(a==0)printf("Ron\n");
    else if(f==0)printf("Hermione\n");
    else if(e==0)printf("Ron\n");
    
    return 0;
}