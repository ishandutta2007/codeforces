# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>

using namespace std;
    
int main()
{
    int l1,r1,l2,r2;
    scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    if(((l1<=r2+1)&&(r2<=2*(l1+1)))||((r1<=l2+1)&&(l2<=2*(r1+1))))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}